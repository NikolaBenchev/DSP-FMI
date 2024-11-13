#include<iostream>

template<typename T>
struct Node{
    T value;
    Node* next;
    Node* prev;
};


Node<int>* removeConsecutiveDuplicates(Node<int>* head) {
    Node<int>* curr = head->next;
    while(curr != head) {
        while(curr->next != head) {
            if(curr->value != curr->next->value)
                break; 
            Node<int>* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        if(curr->next)
            curr->next->prev = curr;
        curr = curr->next;
    }
    return head;
}

Node<int>* mirror(Node<int>* head) {
    Node<int>* curr = head->prev;
    Node<int>* currMirror = head->prev;

    while(curr != head) {
        std::cout << curr->value << std::endl;
        Node<int>* mirrorNext = new Node<int>{curr->value, nullptr, currMirror};
        currMirror->next = mirrorNext;
        currMirror = currMirror->next;
        curr = curr->prev;
    }
    head->prev = currMirror;
    currMirror->next = head;

    return head;
}

void print(Node<int>* head) {
    Node<int>* curr = head ->next;
    while(curr != head) {
        std::cout << curr->value << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main() {
    Node<int>* head = new Node<int>{1, nullptr, nullptr};
    int n;
    std::cin >> n;
    Node<int>* last = head;
    for(int i = 0; i < n; i++) {
        int currValue;
        std::cin >> currValue;
        Node<int>* currNode = new Node<int>{currValue, nullptr, last};
        last->next = currNode;
        last = currNode;
    }
    last->next = head;
    head->prev = last;

    head = mirror(head);
    // head = removeConsecutiveDuplicates(head);
    print(head);
    return 0;
}