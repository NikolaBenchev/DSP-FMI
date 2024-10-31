#include<stack>
#include<stddef.h>

template<class T>
class QueueFromStacks {
public:
    void push(const T &el) {
        this->pusher.push(el);
    }

    void push(T &&el) {
        this->pusher.push(std::move(el));
    }
    
    void pop() {
        copyToPopper();

        this->popper.pop();
        this->removed++;
    }
    
    const T &front() const {
        copyToPopper();

        return this->popper.top();
    }

    T &front() {
        copyToPopper();

        return this->popper.top();        
    }
    
    const T &back() const {
        return this->pusher.top();
    }

    T &back() {
        return this->pusher.top();
    }
    

    bool empty() const {
        return this->size() == 0;
    }

    std::size_t size() const {
        return pusher.size();
    }
private:
    std::stack<T> pusher, popper;
    int removed = 0;

    void copyToPopper() {
        if(!this->popper.empty())
            return;

        const T back = this->pusher.top();
        while(!this->pusher.empty()) {
            this->popper.push(this->pusher.top());
            this->pusher.pop();
        }
        this->pusher.push(back);
        this->removed = 0;
    }
};