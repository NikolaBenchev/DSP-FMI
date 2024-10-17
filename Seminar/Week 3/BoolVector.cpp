#include "BoolVector.hpp"
#include <cstdint>

BoolVector::BoolVector() : size(0), arr(0){};
// (size + 7) за да закръгляме нагоре, >> 3 <=> / 8
BoolVector::BoolVector(int size) : size(size), arr((size + 7) >> 3){};

// BoolVectorProxy BoolVector::operator[](int i) { return BoolVectorProxy(); }

std::size_t BoolVector::size() {
    return size;
};

void BoolVector::push_back(bool b) {

}