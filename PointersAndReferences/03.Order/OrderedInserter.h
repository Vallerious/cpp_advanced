#pragma once

#include <vector>
#include "Company.h"

class OrderedInserter {
private:
    std::vector<const Company*>* companies;
public:
    OrderedInserter(std::vector<const Company*>& companies) : companies(&companies) {}

    void insert(const Company* c) {
        auto it = companies->begin();

        while (it != companies->end() && (*it)->getId() < c->getId()) {
            it++;
        }

        this->companies->insert(it, c);
    }
};