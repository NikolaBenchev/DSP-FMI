#include <iostream>
#include <cstdint>
#include <vector>

class BoolVector {

public:
    BoolVector();
    BoolVector(int size);

    std::size_t size();

    void push_back(bool b);

    class BoolVectorProxy {
        uint8_t *source;
        uint8_t position;
        
        BoolVectorProxy(&source, std::size_t position) {};

        BoolProxy &operator=(bool b) {
            *source &= ~(1 << position);
            b << position;
        };

        operator bool() {
            return (*source & (1 << position)) >> position;
        }
    };

    BoolVectorProxy operator[](int i) {
        return BoolVectorProxy();
    };

private:

    std::size_t size;
    // unsigned int 8 bit
    std::vector<uint8_t> arr;

};