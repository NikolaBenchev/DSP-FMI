#include<queue>
#include<vector>

template<class T>
class ParticleSystem {
public:
    using Id = int;
    std::size_t size() {
        return elements.size() - empty.size();
    }

    Id add(T &el) {
        if(!empty.empty()) {
            Id free = empty.front();
            elements[free].value = el;
            elements[free].valid = true;
            empty.pop();
            return free;
        }
        elements.push_back(ElementData{el, true});
        return elements.size() - 1;
    }

    void remove(Id id) {
        if(id >= elements.size()) throw std::invalid_argument("Invalid id");
        if(!elements[id].valid) throw std::invalid_argument("Invalid id");

        empty.push(id);
        elements[id].valid = false;
    }

    T &operator[](Id id) {
        if(id >= elements.size()) throw std::invalid_argument("Invalid id");
        if(!elements[id].valid) throw std::invalid_argument("invalid id");

        return elements[id].value;
    }

    //TODO: iterators: begin() end()
protected:
    struct ElementData {
        T value;
        bool valid;
    };

    std::vector<ElementData> elements;
    std::queue<Id> empty;
};