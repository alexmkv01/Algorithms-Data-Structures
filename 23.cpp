#include <vector>
#include <string>

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0){
            return NULL;
        }
        
        while (lists.size() > 1){
            vector<ListNode*> mergedList;
            for (int i=0; i<lists.size(); i+=2){
                ListNode* l1 = lists[i];
                ListNode* l2;
                if (i+1 < lists.size()){
                    l2 = lists[i+1];
                } else {
                    l2 = nullptr;
                }
                mergedList.push_back(mergeTwoLists(l1, l2));
            }
            lists = mergedList;
        }
        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (list1 != nullptr && list2 != nullptr){
            if (list1->val <= list2->val){
                tail->next = list1;
                list1 = list1->next; // increment
            } else {
                tail->next = list2;
                list2 = list2->next; // increment
            } 
            tail = tail->next;
        }

        // if some elements in list1/list2 still remain
        if (list1 != nullptr){
            tail->next = list1;
        }
        if (list2 != nullptr){
            tail->next = list2;
        }
        return dummy->next;
    }

};