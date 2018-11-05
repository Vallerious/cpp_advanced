#ifndef DIGIT_FILTER_H
#define DIGIT_FILTER_H

#include "Filter.h"

class DigitFilter : public Filter {
    bool shouldFilterOut(char symbol) const override {
        return symbol >= '0' && symbol <= '9';
    }
};

#endif // !DIGIT_FILTER_H
