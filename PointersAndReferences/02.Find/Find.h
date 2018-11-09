#pragma once

#include <vector>

#include "Company.h"

Company* find(const std::vector<Company*>& companies, int id) {
    size_t len = companies.size();

    for (size_t i = 0; i < len; i++) {
        if (companies[i]->getId() == id) {
            return companies[i];
        }
    }

    return nullptr;
}