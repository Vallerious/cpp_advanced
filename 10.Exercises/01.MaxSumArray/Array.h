#ifndef ARRAY_H
#define ARRAY_H

template<class T>
class Array {
private:
    T* data;
    size_t size;
public:
    Array(size_t size) : size(size), data(new T[size]) {
    }

    Array(const Array& other) {
        this = other;
    }

    Array& operator=(const Array& other) {
        if (this == &other) {
            return *this;
        }

        delete[] this->data;

        this->data = new T[other.getSize()];
        this->size = other.size;
        for (size_t i = 0; i < other.getSize(); i++) {
            this->data[i] = other[i];
        }
    }

    const T& operator[](size_t idx) const {
        return this->data[idx];
    }

    T& operator[](size_t idx) {
        return this->data[idx];
    }

    size_t getSize() const {
        return this->size;
    }

    T* begin() {
        return this->data;
    }

    T* end() {
        return this->data + this->size;
    }

    ~Array() {
        delete[] this->data;
    }
};

#endif // !ARRAY_H
