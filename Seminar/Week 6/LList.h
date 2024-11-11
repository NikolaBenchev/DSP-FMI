#pragma once
#include<algorithm>
#include "./Allocator.h"

template<class T>
class LList {
public: 
    LList(Allocator<Node> a): head(nullptr), tail(nullptr), allocator(a) {};

    LList(const LList<T> &&other): head(other.head), tail(other.tail) {
        other.head = nullptr;
        other.tail = nullptr;
    }

    LList(const LList<T> &other) {
        copy(other);
    }

    LList &operator=(LList<T> &&other) {
        std::swap(head, other.head);
        std::swap(tail, other.tail);
        return *this;
    }

    LList &operator=(const LList<T> &other) {
        if(&other == this) return *this;
        copy(other);
    }

    void copy(const LList<T> &other) {
        deallocate();
        if(!other->head) {
            return;
        }
        for(Node* curr = other->head; curr; curr = curr->next) {
            push_back(other->value);
        }
    }


    ~LList() {
        deallocate();
    }

    void deallocate() {
        while(head) {
            Node* curr = head;
            head = head->next;
            delete curr;
        }
        head = nullptr;
        tail = nullptr;
    }

    void push_back(const T& value) {
        Node* newNode = new Node{nullptr, value};
        if(!head){
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void push_front(const T& value) {
        Node* newNode = new Node{head, value};
        if(!tail) {
            head = tail = newNode;
            return;
        }
        head = newNode;
    }

    struct Node {
        Node* next;
        T value;
    };

    void print() {
        Node* curr = head;
        while(curr) {
            std::cout << curr->value << std::endl;
            curr = curr->next;
        }
    }

private:
    Node* head;
    Node* tail;
    Allocator<Node> &allocator;
};