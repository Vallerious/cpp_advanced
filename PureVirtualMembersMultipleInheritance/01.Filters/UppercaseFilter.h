#ifndef UPPERCASE_FILTER_H
#define UPPERCASE_FILTER_H

#include "Filter.h"

class UppercaseFilter : public Filter {
protected:
    bool shouldFilterOut(char symbol) const override {
        return symbol >= 'A' && symbol <= 'Z';
    }
};

#endif // !UPPERCASE_FILTER_H
