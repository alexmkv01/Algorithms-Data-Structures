#include <iostream>
#include <vector>

using namespace std;

class ListNode_ {
public:
    // attributes
    int val;
    ListNode_* next;
    ListNode_* prev;

    // constructor
    ListNode_(int val){
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class MyLinkedList {
public:
    // attributes
    ListNode_ *head;
    ListNode_ *tail;

    // constructor
    MyLinkedList() {
        head = new ListNode_(-1);
        tail = new ListNode_(-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int index) {
        ListNode_ *cur = head->next;
        int i=0;
        while (cur != tail){
            if (i==index){
                return cur->val;
            }
            i++;
            cur = cur->next;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        ListNode_ *newNode = new ListNode_(val);
        newNode->next = head->next;
        newNode->prev = head;

        head->next->prev = newNode;
        head->next = newNode;
    }
    
    void addAtTail(int val) {
        ListNode_ *newNode = new ListNode_(val);
        newNode->next = tail;
        newNode->prev = tail->prev;
        

        tail->prev->next = newNode;
        tail->prev = newNode;
    }
    
    void addAtIndex(int index, int val) {
        ListNode_ *newNode = new ListNode_(val);
        ListNode_ *cur = head->next;
        int i=0;

        while (cur != tail){
            if (i==index){
                // add
                newNode->next = cur;
                newNode->prev = cur->prev; 
                cur->prev->next = newNode;
                cur->prev = newNode;

                break; 
            }
            i++;
            cur = cur->next;
        }
        if (cur == tail && i == index) { // If we've reached the end and the index is valid, add at tail
            addAtTail(val);
        }
    }
    
    void deleteAtIndex(int index) {
        ListNode_ *cur = head->next;
        int i=0;

        while (cur != tail){
            if (i==index){
                // remove
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                delete cur; // Free the memory of the node that is being removed
                break;
            }
            i++;
            cur = cur->next;
        }
    }

    void print() {
        ListNode_* cur = head->next;
        while (cur != tail) {
            std::cout << cur->val << " -> ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }
};