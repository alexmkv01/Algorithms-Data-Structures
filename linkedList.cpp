#include <vector>
using namespace std;

class ListNode {
    public:
        // attributes
        int val;
        ListNode *next = nullptr;

        // constructor
        ListNode(int val){
            this->val = val;
        }
};

class LinkedList {
    public:
        // attributes
        ListNode *head;
        ListNode *tail;

        // constructor
        LinkedList() {
            head = new ListNode(-1);
            tail = head;
        }

        // methods
        int get(int index) {
            ListNode* cur = head->next;
            int i = 0;
            while (cur != nullptr){
                if (i==index){
                    return cur->val;
                }
                i++;
                cur = cur->next;   
            }
            return -1;
        }

        void insertHead(int val) {
            ListNode* newNode = new ListNode(val);
            newNode->next = head->next;
            head->next = newNode;
            if (newNode->next == nullptr) {  // If list was empty before insertion
                tail = newNode;
            }
        }
        
        void insertTail(int val) {
            tail->next = new ListNode(val);
            tail = tail->next;
        }

        bool remove(int index) {
            ListNode* cur = head;
            int i = 0;
            while (cur != nullptr && i<index){
                i++;
                cur = cur->next;   
            }

            // Remove the node ahead of cur
            if (cur != nullptr && cur->next != nullptr) {
                if (cur->next == tail) {
                    tail = cur; // when removing second last node
                }
                ListNode* toDelete = cur->next;
                cur->next = cur->next->next;
                delete toDelete;
                return true;
            }
            return false;
        }

        // Method to get values of the linked list
        vector<int> getValues() {
            vector<int> myArr;
            ListNode* cur = head->next;

            while (cur != nullptr) {
                myArr.push_back(cur->val);
                cur = cur->next;
            }
            return myArr;
        }
    };
