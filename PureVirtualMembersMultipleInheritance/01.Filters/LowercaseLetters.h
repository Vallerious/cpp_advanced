#ifndef LOWERCASE_FILTER_H
#define LOWERCASE_FILTER_H

#include "Filter.h"

class LowercaseFilter : public Filter {
protected:
    bool shouldFilterOut(char symbol) const override {
        return symbol >= 'a' && symbol <= 'z';
    }
};

#endif // !LOWERCASE_FILTER_H
