#ifndef DIGIT_EXTRACTOR_H
#define DIGIT_EXTRACTOR_H

#include "BufferedExtractor.h"

class DigitExtractor : public BufferedExtractor {
private:
    bool process(char symbol, std::string& output) override {
        if (isdigit(symbol)) {
            this->buffer << symbol;
            output = this->buffer.str();
            buffer.str("");
            buffer.clear();

            return true;
        }
        else {
            return false;
        }
    }

    bool shouldBuffer(char symbol) override {
        return false;
    }
public:
    DigitExtractor(std::istream& stream) : BufferedExtractor(stream) {}
};

#endif // !DIGIT_EXTRACTOR_H
