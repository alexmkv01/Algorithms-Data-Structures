#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // base case
        if (head == nullptr || head->next == nullptr) {
            return head;
        }       

        // recursive case
        ListNode* newHead = reverseList(head->next); // newHead is pointer to the head of reversed list
        head->next->next = head; // reversal
        head->next = nullptr;
        return newHead;
    }
};
                 
