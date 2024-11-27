#include<stdexcept>
#include<cstddef>

template <class T>
class Vector{
	public:
		Vector(): currSize(0), maxSize(1) {}
		~Vector() {
			delete[] arr;
		}

		Vector(const Vector& other) : arr(new T[other.currSize]), currSize(other.currSize), maxSize(other.maxSize) {
			for(int i = 0; i < other->maxSize; i++) {
				this->arr[i] = other[i];
			}
		}

		Vector& operator=(const Vector& other) {
			if(this == &other) return *this;
			
			copyFrom(other);
			return *this;
		}

		Vector(Vector&& other) {
			moveFrom(other);
		}

		Vector& operator=(Vector&& other) {
			if(this == other) return *this;

			free();
			moveFrom(other);
			return *this;
		}


		//TODO: validation for the index
		T& operator[](size_t index) {
			return this->arr[index];
		}

		//TODO: validation for the index
		const T& operator[](size_t index) const {
			return this->arr[index];
		}

		void push(T el) {
			if(this->currSize == this->maxSize)
				resize(this->maxSize * 2);

			this->arr[this->currSize] = el;
			this->currSize += 1;
		}

		T pop() {
			if(this->currSize == 0) 
				throw std::length_error("Already empty!");
			
			this->currSize -= 1;
			
			if(this->currSize * 4 < this->maxSize)
				this->resize(this->maxSize / 2);

			return this->arr[currSize];
		}

		size_t size() {
			return this->currSize;
		}

	private:
		size_t currSize, maxSize;
		T* arr;

		void copyFrom(const Vector& other) {
			delete[] arr;
			this->currSize = other.size;
			this->maxSize = other.maxSize;
			this->arr = new T[other.maxSize];
			for(int i = 0; i < other.size; i++) {
				this->arr[i] = other->arr[i];
			}
		}

		void moveFrom(const Vector&& other) {
			this->arr = other.arr;
			this->currSize = other.size;
			this->maxSize = other.maxSize;
			other.arr = nullptr;
		}

		void resize(size_t newSize) {
			this->maxSize = newSize;
			T* newArr = arr;
			this->arr = new T[maxSize];
			for(int i = 0; i < this->currSize; i++) {
				this->arr[i] = newArr[i];
			}
		}

		void free() {
			this->currSize = 0;
			this->maxSize = 1;
			delete[] arr;
		}
};
