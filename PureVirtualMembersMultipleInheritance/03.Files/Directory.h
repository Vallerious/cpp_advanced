#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <string>

#include "FileSystemObjectsContainer.h"
#include "FileSystemObject.h"

class Directory : public FileSystemObjectsContainer, public FileSystemObject {
private:
	std::vector<std::shared_ptr<FileSystemObject> > files;
public:
	Directory(std::string name) : FileSystemObject(name) {}

	void add(const std::shared_ptr<FileSystemObject>& obj) override {
		this->files.push_back(obj);
	}

	size_t getSize() const override {
		int size = 0;

		for (auto o : files) {
			size += o->getSize();
		}

		return size;
	}
};
#endif // !DIRECTORY_H
