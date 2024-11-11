#pragma once
#include "../Week 5/ParticleSystem.hpp"

template<typename T>
class Allocator : ParticleSystem<T> {
public:
    T* allocate() {
        auto id = this->add(T());
        return &(*this)[id];
    }

    void free(T* ptr) {
        if(!ptr) return;

        int id = (ptr - &this->elements[0]) 
            / sizeof(ParticleSystem<T>::ElementData);
        
        try{
            this->remove(id);
        }catch(...) {
            throw std::invalid_argument("Invalid pointer to free");
        }
    }

    bool checkForLeaks() {
        return this->size() == 0;
    }
private: 
};