#include <iostream>

using namespace std;

// Doubly Linked List Node
class Node {
public:
    // attributes
    int val;
    Node *next = nullptr;
    Node *prev = nullptr;

    // constructor
    Node(int val){
        this->val = val;
    }
};

// Linked List implementation of Double Ended Queue
class Deque {
private:
    Node *head;
    Node *tail;

public:
    Deque() {
        this->head = new Node(-1);
        this->tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
    }

    bool isEmpty() {
        return head->next == tail;
    }

    void append(int value) {
        Node *newNode = new Node(value);
        tail->prev->next = newNode;
        newNode->prev = tail->prev;
        newNode->next = tail;
        tail->prev = newNode;
    }

    void appendleft(int value) {
        Node *newNode = new Node(value);
        head->next->prev = newNode;
        newNode->next = head->next;
        newNode->prev = head;
        head->next = newNode;
    }

    int pop() {
        if (isEmpty()){
            return -1;
        }
        Node *targetNode = tail->prev;
        Node *prevNode = targetNode->prev;

        int val = targetNode->val;
        prevNode->next = tail;
        tail->prev = prevNode;

        delete targetNode;
        return val;
    }

    int popleft() {
        if (isEmpty()){
            return -1;
        }
        Node *targetNode = head->next;
        Node *nextNode = targetNode->next;

        int val = targetNode->val;
        head->next = nextNode;
        nextNode->prev = head;
        delete targetNode;
        return val;
    }

    void print(){
        Node *cur = head->next;
        while (cur != tail){
            std::cout << cur->val << " -> ";
            cur = cur->next;
        }
        std::cout << "\n";
    }
};

int main(){

    Deque *myQueue = new Deque();
    myQueue->append(3);
    myQueue->append(1);
    myQueue->appendleft(-2);
    myQueue->pop();
    myQueue->popleft();

    myQueue->print();

}