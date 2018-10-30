#ifndef AVERAGE_AGGREGATOR_H
#define AVERAGE_AGGREGATOR_H

#include <sstream>

#include "Aggregator.h"

class AverageAggregator : public StreamAggregator {
private:
    int sum;
public:
    AverageAggregator(std::istream& stream) : StreamAggregator(stream), sum(0) {
        this->aggregationResult = 0;
    }

protected:
    void aggregate(int next) override {
        StreamAggregator::aggregate(next);

        this->sum += next;
        this->aggregationResult = this->sum / this->getNumAggregated();
    }
};

#endif // !AVERAGE_AGGREGATOR_H