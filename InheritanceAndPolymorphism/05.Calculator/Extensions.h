#ifndef EXTENSIONS_H
#define EXTENSIONS_H

#include <stack>

#include "InputInterpreter.h"
#include "DivisionOperation.h"
#include "MemorySave.h"
#include "Operation.h"

class ExtendedInputInterpreter : public InputInterpreter {
private:
	CalculationEngine& engine;
	std::stack<std::shared_ptr<Operation> > memory;
public:
	ExtendedInputInterpreter(CalculationEngine& engine) : InputInterpreter(engine), engine(engine) {}

	std::shared_ptr<Operation> getOperation(std::string operation) {
		std::shared_ptr<Operation> op = InputInterpreter::getOperation(operation);

		if (op != nullptr) {
			return op;
		}

		if (operation == "/") {
			return std::make_shared<DivisionOperation>();
		}
		else if (operation == "ms") {
			std::shared_ptr<Operation> op = std::make_shared<MemorySave>(MemorySave(this->engine.getCurrentResult()));
			memory.push(op);

			return op;
		}
		else if (operation == "mr") {
			std::shared_ptr<Operation> op = this->memory.top();
			this->memory.pop();

			engine.pushNumber(op->getResult());

			return std::make_shared<MemorySave>(MemorySave(this->engine.getCurrentResult()));
		}
	}
};

std::shared_ptr<ExtendedInputInterpreter> buildInterpreter(CalculationEngine& engine) {
	return std::make_shared<ExtendedInputInterpreter>(ExtendedInputInterpreter(engine));
}

#endif EXTENSIONS_H