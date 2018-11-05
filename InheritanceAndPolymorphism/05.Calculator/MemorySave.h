#ifndef MEMORY_SAVE_H
#define MEMORY_SAVE_H

#include <vector>

#include "Operation.h"

class MemorySave : public Operation {
	int result;
public:
	MemorySave(int result): result(result) {}

	void addOperand(int operand) override {}

	bool isCompleted() override {
		return true;
	}

	int getResult() override {
		return this->result;
	}
};

#endif // !MEMORY_SAVE_H