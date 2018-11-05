#ifndef INITIALIZATION_H
#define INITIALIZATION_H

#include "CommandInterface.h"
#include "TextTransform.h"

class FullCommandInterface : public CommandInterface {
private:
    static std::string cutText;

    class CutTransform : public TextTransform {
    public:
        virtual void invokeOn(std::string& text, int startIndex, int endIndex) override {
            if (startIndex == endIndex) {
                FullCommandInterface::cutText.empty();
            }
            else {
                FullCommandInterface::cutText = text.substr(startIndex, endIndex - startIndex);
                text = text.erase(startIndex, endIndex - startIndex);
            }
        }
    };

    class PasteTransform : public TextTransform {
    public:
        virtual void invokeOn(std::string& text, int startIndex, int endIndex) override {
            text = text.replace(startIndex, endIndex - startIndex, FullCommandInterface::cutText);
        }
    };
public:
    FullCommandInterface(std::string& text) : CommandInterface(text) {
		this->init();
	}
protected:
    std::vector<Command> initCommands() override {
        std::vector<Command> commands = CommandInterface::initCommands();

        commands.push_back(Command("cut", std::make_shared<CutTransform>()));
        commands.push_back(Command("paste", std::make_shared<PasteTransform>()));

        return commands;
    }
};

std::string FullCommandInterface::cutText;

std::shared_ptr<CommandInterface> buildCommandInterface(std::string& text) {
    return std::make_shared<FullCommandInterface>(text);
}

#endif // !INITIALIZATION_H