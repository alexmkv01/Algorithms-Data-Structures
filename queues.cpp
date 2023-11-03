// Doubly Linked List Node
class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int value) : value(value), next(nullptr), prev(nullptr) {}
};

// Linked List implementation of Double Ended Queue
class Deque {
private:
    Node* dummyHead;
    Node* dummyTail;

public:
    Deque() {
        // Initialize dummy head and tail nodes
        dummyHead = new Node(0);
        dummyTail = new Node(0);

        // Connect dummy head and tail nodes
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }

    bool isEmpty() {
        return dummyHead->next == dummyTail;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        Node* prevNode = dummyTail->prev;

        newNode->next = dummyTail;
        newNode->prev = prevNode;

        prevNode->next = newNode;
        dummyTail->prev = newNode;
    }

    void appendleft(int value) {
        Node* newNode = new Node(value);
        Node* nextNode = dummyHead->next;

        newNode->next = nextNode;
        newNode->prev = dummyHead;

        nextNode->prev = newNode;
        dummyHead->next = newNode;
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }
        Node* targetNode = dummyTail->prev;
        Node* prevNode = targetNode->prev;
        int value = targetNode->value;

        prevNode->next = dummyTail;
        dummyTail->prev = prevNode;

        delete targetNode; // Free the memory
        return value;
    }

    int popleft() {
        if (isEmpty()) {
            return -1;
        }
        Node* targetNode = dummyHead->next;
        Node* nextNode = targetNode->next;
        int value = targetNode->value;

        dummyHead->next = nextNode;
        nextNode->prev = dummyHead;

        delete targetNode; // Free the memory
        return value;
    }
};