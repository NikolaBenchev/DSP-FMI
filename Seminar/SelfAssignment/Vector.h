typename <class T>
class Vector {
	public:
		Vector(): size(0), maxSize(1) {}
		~Vector() : size(0), maxSize(1) {
			delete[] this->arr;
		}

		Vector Vector(const Vector& other) {
			if(this->maxSize < other->maxSize) {
				this->arr = new T[other->maxSize];
			}
			
			for(int i = 0; i < other->maxSize; i++) {
				this->arr[i] = other[i];
			}
			
			this->size = other->size;
			this->maxSize = other->maxSize;
			return *this;
		}
		
		T operator[](int index) {
			return this->arr[index];
		}

		const T operator[](int index) {
			return this->arr[index];
		}


		void push_back(T el) {
		
		}

		void pop_back() {
		
		}

	private:
		size_t size, maxSize;
		T arr[];
};
