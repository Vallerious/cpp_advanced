#ifndef NUMBERS_EXTRACTOR_H
#define NUMBERS_EXTRACTOR_H

#include "BufferedExtractor.h"

class NumbersExtractor : public BufferedExtractor {
    bool shouldBuffer(char symbol) override {
        return isdigit(symbol);
    }
public:
    NumbersExtractor(std::istream& stream) : BufferedExtractor(stream) {}
};

#endif // !NUMBERS_EXTRACTOR_H