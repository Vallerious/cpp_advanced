#pragma once

#include <vector>
#include <string>
#include <utility>
#include "Company.h"
typedef unsigned char byte;

std::vector<Company> readCompaniesFromMemory(byte* memory, size_t numCompanies) {
    std::vector<Company> companies;

    while (companies.size() < numCompanies) {
        int companyId = *(memory++);
        std::string companyName;

        while ((*memory) != '\0') {
            companyName += *(memory++);
        }
        memory++;
        int numEmployees = *(memory++);
        std::vector<std::pair<char, char> > initials;
        
        for (size_t i = 0; i < numEmployees; i++) {
            char fi = *(memory++);
            char si = *(memory++);

            initials.push_back(std::make_pair(fi, si));
        }
        
        Company c{ companyId, companyName, initials };

        companies.push_back(c);
    }

    return companies;
}