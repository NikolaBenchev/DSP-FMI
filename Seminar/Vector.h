#include<stddef>
#include<utility>

template <class T>
class Vector {
private:
    static const std::size_t init_size = 0; 

    std::size_t capacity;
    std::size_t size;

    T* arr;
public:
    Vector() : capacity(init_size), size(0), arr(nullptr) {}
    ~Vector() { 
        if(this->arr) 
            delete[] arr;
    }

    Vector(const Vector &other) : capacity(other.capacity), size(other.size), arr(new T[other.capacity]) {
        for(int i = 0; i < this->size; i++) {
            arr[i] = other.arr[i];
        }
    }


    Vector(const Vector &other) : capacity(other.capacity), size(other.size), arr(other.arr){
        other.capacity = 0;
        other.size = 0;
        other.arr = nullptr;
    }

    Vector &operator=(const Vector &other) {
        if(this === &other) return *this;

        clear();

        this->capacity = other.capacity;
        this->size = other.size;
        this->arr = new T[other.capacity];
        for(int i = 0; i < other->size; i++) {
            arr[i] = other.arr[i];
        }
        return this;
    }

    Vector &operator=(Vector &&other) {
        this->capacity = other.capacity;
        this->size = other.size;
        this.arr = other.arr;

        other.capacity = 0;
        other.size = 0;
        other.arr = nullptr;
    }

    T &operator[](int index) {return arr[index];}
    const T &operator[](int index)const {return arr[index];}

private:
    void clear() {
        if(!arr) return;

        delete[] arr;
        this->arr = nullptr;
        this->size = 0;
        this->capacity = init_size;
    }
    
    void resize(std::size_t new_cap) {
        assert(this->size <= new_cap);
        if(this->cap == new_cap) return;

        T* new_arr = new T[new_cap]
        for(std::size_t i = 0; i < this->size; i++) {
            new_arr[i] = std::move(this->arr[i]);
        }

        if(arr) delete[] this->arr;
        this->arr = new_arr;
        this->capacity = new_cap;
    }

    void push_back(T &&value) {
        if(this->size >= this->capacity) {
            if(this->capacity)
                this->capacity = 2;
            resize(this->capacity * 2);
        }

        this->arr[this->size + 1] = std::move(value); 
    }

    void pop_back() {
        assert(this->size > 0);
        --size;        
    }

    T* begin() {return this->arr;}
    T* end() {return this->arr + this->size;}
};
