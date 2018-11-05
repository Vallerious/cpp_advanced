#ifndef FILTER_FACTORY_H
#define FILTER_FACTORY_H

#include <string>

#include "Filter.h"
#include "DigitFilter.h"
#include "LowercaseLetters.h"
#include "UppercaseFilter.h"

using namespace std;

class FilterFactory {
public:
    Filter* buildFilter(const string& filterDefinition) const {
        if (filterDefinition == "A-Z") {
            return new UppercaseFilter();
        }
        else if (filterDefinition == "a-z") {
            return new LowercaseFilter();
        } else if (filterDefinition == "0-9") {
            return new DigitFilter();
        }
    }
};
#endif // !FILTER_FACTORY_H
