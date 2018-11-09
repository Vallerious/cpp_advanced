#ifndef PROFIT_REPORT_H
#define PROFIT_REPORT_H

#include <string>
#include <sstream>
#include <map>

#include "Company.h"
#include "ProfitCalculator.h"

std::string getProfitReport(Company* begin, Company* end, const std::map<int, ProfitCalculator>& profitCalcs) {
    std::string ss;
    begin--;
    while (begin++ != end) {
        ss += (begin->getName() + " = " + std::to_string(profitCalcs.at(begin->getId()).calculateProfit(*begin)) + '\n');
    }

    return ss;
}

#endif // !PROFIT_REPORT_H