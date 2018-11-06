#include "IndexedSet.h"

IndexedSet::IndexedSet() {}

IndexedSet::IndexedSet(const IndexedSet& other) {
    *this = other;
}

void IndexedSet::add(const Value& v) {
    this->valuesSet.insert(v);
    this->clearIndex();
}

size_t IndexedSet::size() const {
    return this->valuesSet.size();
}

const Value& IndexedSet::operator[](size_t index) {
    if (this->valuesArray == 0) {
        this->buildIndex();
    }

    return this->valuesArray[index];
}

IndexedSet& IndexedSet::operator=(const IndexedSet& other) {
    if (this == &other) {
        return *this;
    }

    this->valuesSet.clear();

    for (Value v : other.valuesSet) {
        this->valuesSet.insert(v);
    }

    this->clearIndex();
    this->buildIndex();
}

IndexedSet::~IndexedSet() {
    this->clearIndex();
}

void IndexedSet::buildIndex() {
    this->valuesArray = new Value[this->size()];
    int idx = 0;
    for (std::set<Value>::iterator it = this->valuesSet.begin(); it != this->valuesSet.end(); it++) {
        this->valuesArray[idx++] = (*it);
    }
}

void IndexedSet::clearIndex() {
    this->valuesArray = 0;
    delete[] this->valuesArray;
}