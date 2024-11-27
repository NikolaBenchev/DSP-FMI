#include<vector>

template <typename T>
class Node {
public:
    Node(T value) {
        this->value = value;
    }

    void add(Node* toAdd) {
        childNodes.push_back(toAdd);
    }

    void remove(Node* toRemove) {
        for(
            std::vector<Node*>::iterator it = childNodes.begin(); 
            it != childNodes.end();
            it++
        ) {
            if(it == toRemove) {
                childNodes.erase(it);
                break;
            }
        }
    }

    T* getValue() {
        return this->value;
    }

    vector<Node*> getChildNodes() {
        return this->childNodes;
    }
private:
    T value;
    vector<Node*> childNodes;
};