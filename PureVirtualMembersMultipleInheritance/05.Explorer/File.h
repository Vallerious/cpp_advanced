#ifndef FILE_H
#define FILE_H

#include "ByteContainer.h"

class File : public ByteContainer {
public:
	File(std::string name, std::string content) : ByteContainer(name, content) {}
};

#endif // !FILE_H
