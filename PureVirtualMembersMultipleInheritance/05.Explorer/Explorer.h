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
  bool hasShortcuts;
  std::shared_ptr<Shortcuts> shortcuts;
public:
	Explorer(std::vector<std::shared_ptr<FileSystemObject> >& fileSystemObjects) :
      fileSystemObjects(&fileSystemObjects),
      hasShortcuts(false) {}

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
        this->fileSystemObjects->erase(it);
				break;
			}
		}
	}

	void paste() {
		this->fileSystemObjects->push_back(this->cutItem);
	}

	void createShortcut(std::string filename) {
      if (!hasShortcuts) {
          this->shortcuts = std::make_shared<Shortcuts>();

          this->fileSystemObjects->push_back(this->shortcuts);
          this->hasShortcuts = true;
      }

      for (auto it = this->fileSystemObjects->begin(); it != this->fileSystemObjects->end(); it++) {
          if ((*it)->getName() == filename) {
              //this->shortcuts->add(&(*(*it)));
          }
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
