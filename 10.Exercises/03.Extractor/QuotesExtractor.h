#ifndef QUOTES_EXTRACTOR_H
#define QUOTES_EXTRACTOR_H

#include "BufferedExtractor.h"

class QuotesExtractor : public BufferedExtractor {
private:
    bool isBuffering;

    bool shouldBuffer(char symbol) override {
        if (this->isBuffering) {
            if (symbol != '\"') {
                return true;
            }
            else {
                this->isBuffering = false;

                return false;
            }
        }
        else {
            if (symbol == '\"') {
                this->isBuffering = true;

            }

            return false;
        }
    }
public:
    QuotesExtractor(std::istream& stream) : BufferedExtractor(stream), isBuffering(false) {}
};

#endif // !QUOTES_EXTRACTOR_H
