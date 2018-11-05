#ifndef TREE_VIEW_H
#define TREE_VIEW_H

#include <string>
#include <memory>

#include "Directory.h"

std::string getTreeView(const std::vector<std::shared_ptr<FileSystemObject> >& fileObj, int level = 0) {
	std::string tree;

	for (auto f : fileObj) {
		for (int i = 0; i < level; i++) {
			tree += "--->";
		}
		tree += f->getName();
		tree += "\n";

		if (f->getName() == "[shortcuts]") {
			std::vector<std::shared_ptr<FileSystemObject> > childObjects;
			auto shortcut = std::dynamic_pointer_cast<FileSystemObjectsContainer>(f);

			for (auto it = shortcut->begin(); it != shortcut->end(); it++) {
				childObjects.push_back(*it);
			}

			std::sort(childObjects.begin(), childObjects.end(), [](const std::shared_ptr<FileSystemObject> a, const std::shared_ptr<FileSystemObject> b) {
				return a->getName() < b->getName();
			});

			tree += getTreeView(childObjects, level + 1);
		}
		else {
			std::shared_ptr<Directory> dir = std::dynamic_pointer_cast<Directory>(f);

			/*if (dir == nullptr && dir->getName() == "[shortcuts]") {
				dir = std::dynamic_pointer_cast<Shortcuts>(f);
			}*/

			if (dir != nullptr) {
				std::vector<std::shared_ptr<FileSystemObject> > childObjects;

				for (auto c : dir->getFiles()) {
					childObjects.push_back(c);
				}

				std::sort(childObjects.begin(), childObjects.end(), [](const std::shared_ptr<FileSystemObject> a, const std::shared_ptr<FileSystemObject> b) {
					return a->getName() < b->getName();
				});

				tree += getTreeView(childObjects, level + 1);
			}
		}
	}

	return tree;
}

#endif TREE_VIEW_H