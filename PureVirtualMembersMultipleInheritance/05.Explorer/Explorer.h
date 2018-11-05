#ifndef EXPLORER_H
#define EXPLORER_H

#include <vector>
#include <memory>
#include <string>
#include <stack>

#include "FileSystemObject.h"
#include "File.h"
#include "Directory.h"
#include "Shortcuts.h"

class Explorer {
	std::vector<std::shared_ptr<FileSystemObject> >* fileSystemObjects;
	std::shared_ptr<FileSystemObject> cutItem;
public:
	Explorer(std::vector<std::shared_ptr<FileSystemObject> >& fileSystemObjects) : fileSystemObjects(&fileSystemObjects) {}

	void createFile(std::string filename, std::string contents) {
		this->fileSystemObjects->push_back(std::make_shared<File>(filename, contents));
	}

	void createDirectory(std::string name) {
		this->fileSystemObjects->push_back(std::make_shared<Directory>(name));
	}

	void cut(std::string filename) {
		for (auto it = this->fileSystemObjects->begin(); it != this->fileSystemObjects->end(); it++) {
			if ((*it)->getName() == filename) {
				this->cutItem = (*it);
				break;
			}
		}
	}

	void paste() {
		this->fileSystemObjects->push_back(this->cutItem);
	}

	void createShortcut(std::string filename) {
		auto shortcuts = std::make_shared<Shortcuts>();
		bool hasShortcuts = false;

		for (auto it = this->fileSystemObjects->begin(); it != this->fileSystemObjects->end(); it++) {
			if ((*it)->getName() == "[shortcuts]") {
				shortcuts = std::dynamic_pointer_cast<Shortcuts>(*it);
				hasShortcuts = true;
				break;
			}
		}
		
		for (auto it = this->fileSystemObjects->begin(); it != this->fileSystemObjects->end(); it++) {
			if ((*it)->getName() == filename) {
				shortcuts->add(*it);
				break;
			}
		}

		if (!hasShortcuts) {
			this->fileSystemObjects->push_back(shortcuts);
		}
	}

	void navigate(std::string path) {
		if (path == "..") {
			
		}
		else {
			
		}
	}
};

#endif // !EXPLORER_H
