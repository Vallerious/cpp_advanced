#ifndef TYPED_STREAM_H
#define TYPED_STREAM_H

#include <string>
#include <sstream>
#include <vector>

#include "Vector2D.h"

template<typename T>
class TypedStream {
protected:
    TypedStream(const std::string& input) : stream(input) {}

    std::istringstream stream;

    virtual TypedStream<T>& operator>>(T& s) {
        return *this;
    }
public:
    std::string readToEnd() {
        std::ostringstream output;

        std::string value;
        while (this->stream >> value) {
            output << value << " ";
        }

        return output.str();
    }

    virtual ~TypedStream() {}
};

template<>
std::string TypedStream<Vector2D>::readToEnd() {
    std::ostringstream output;

    double value1, value2;
    while (this->stream >> value1 >> value2) {
        output << (std::string) Vector2D { value1, value2 } << " ";
    }

    return output.str();
}

#endif // !TYPED_STREAM_H