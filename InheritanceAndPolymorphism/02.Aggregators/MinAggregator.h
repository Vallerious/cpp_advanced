#ifndef MIN_AGGREGATOR_H
#define MIN_AGGREGATOR_H

#include <sstream>

#include "Aggregator.h"

class MinAggregator : public StreamAggregator {
public:
    MinAggregator(std::istream& stream) : StreamAggregator(stream) {
        this->aggregationResult = INT_MAX;
    }

protected:
    void aggregate(int next) override {
        StreamAggregator::aggregate(next);

        if (next < this->aggregationResult) {
            this->aggregationResult = next;
        }
    }
};

#endif // !MIN_AGGREGATOR_H