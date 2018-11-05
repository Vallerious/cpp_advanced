#ifndef BYTE_CONTAINER_H
#define BYTE_CONTAINER_H

#include <string>

#include "FileSystemObject.h"

class ByteContainer : public FileSystemObject {
private:
	std::string content;
public:
	ByteContainer(std::string name, std::string content) : FileSystemObject(name), content(content) {}

	size_t getSize() const override {
		return this->content.size();
	}

	std::string getBytes() const {
		return this->content;
	}
};
#endif // !BYTE_CONTAINER_H
