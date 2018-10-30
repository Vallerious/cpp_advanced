#ifndef SUM_AGGREGATOR_H
#define SUM_AGGREGATOR_H

#include <sstream>

#include "Aggregator.h"

class SumAggregator : public StreamAggregator {
public:
    SumAggregator(std::istream& stream) : StreamAggregator(stream) {
        this->aggregationResult = 0;
    }
protected:
    void aggregate(int next) override {
        StreamAggregator::aggregate(next);

        // Sum specific logic starts here...
        this->aggregationResult += next;
    }
};

#endif // !SUM_AGGREGATOR_H