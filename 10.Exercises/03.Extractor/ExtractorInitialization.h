#ifndef EXTRACTOR_INITIALIZATION_H
#define EXTRACTOR_INITIALIZATION_H

#include <memory>

#include "Extractor.h"
#include "DigitExtractor.h"
#include "NumbersExtractor.h"
#include "QuotesExtractor.h"

std::shared_ptr<Extractor> getExtractor(const std::string& type, std::istream& s) {
    if (type == "digits") {
        return std::make_shared<DigitExtractor>(s);
    }
    else if (type == "numbers") {
        return std::make_shared<NumbersExtractor>(s);
    }
    else if (type == "quotes") {
        return std::make_shared<QuotesExtractor>(s);
    }

    return nullptr;
}

#endif // !EXTRACTOR_INITIALIZATION_H