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

	std::vector<std::shared_ptr<FileSystemObject> >::const_iterator begin() const override {
		return this->files.begin();
	}

	std::vector<std::shared_ptr<FileSystemObject> >::const_iterator end() const override {
		return this->files.end();
	}

	void remove(std::shared_ptr<FileSystemObject> obj) override {
		this->files.erase(std::find(this->files.begin(), this->files.end(), obj));
	}

	size_t getSize() const {
		size_t sum = 0;

		for (auto f : this->files) {
			sum += f->getSize();
		}

		return sum;
	}

	std::vector<std::shared_ptr<FileSystemObject> > getFiles() const {
		return this->files;
	}
};
#endif // !DIRECTORY_H
