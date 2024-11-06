#include<iostream>

template <typename T>
class Node {
public:
    T value;  // Стойност, съхранена във възела.
    Node<T>* next; // Указател към евентуалния следващ елемент.

    Node(T value = T(), Node* next = nullptr)
      : value(value), next(next)
    { }
};

template <typename T>
void deallocate(Node<T>* head) {
    while(head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
unsigned int countOf(const Node<T>* head, const T& value) {   
    unsigned int counter = 0;

    while(head != nullptr) {
        if(head->value == value)
            counter++;

        head = head->next;
    }

    return counter;
}

template <typename T>
unsigned int countOfRec(const Node<T>* head, const T& value) {
    if(head == nullptr)
        return 0;
    
    return  (head->value == value ? 0 : 1) + countOfRec(head->next, value);
}

template <typename T>
Node<T>* removeAll(Node<T>* head, const T& value) {
    while(head != nullptr) {
        if(head->value != value)
            break;
        head = head->next;
    }

    Node<T>* prev = head;
    Node<T>* curr = head;
    while(curr != nullptr) {
        if(curr->value != value) {
            prev->next = curr;
            prev = curr;
            curr = curr->next;
        } else {
            prev->next = nullptr;
            Node<T>* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    return head;
}

template <typename T>
Node<T>* reverse(Node<T>* head) {
    Node<T>* prev = nullptr;
    
    while(head != nullptr) {
        Node<T>* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

int main() {
    Node<int>* head = new Node<int>(
        1, 
        new Node<int>(
            2, 
            new Node<int>(
                3, 
                new Node<int>(
                    1,
                    nullptr
                )
            )
        )
    );

    head = reverse(head);
    std::cout << "remove " << std::endl;
    while(head != nullptr) {
        std::cout << head->value << std::endl;
        head = head->next;
    }   
    // std::cout <<  << std::endl;
    deallocate(head);
    return 0;
}

/*
    1 4 5
    1 3 4 
    2 6
*/ 