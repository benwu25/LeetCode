/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        } else if (list1 == nullptr) {
            return list2;
        } else if (list2 == nullptr) {
            return list1;
        }
        ListNode *front;
        if (list1->val < list2->val) {
            front = list1;
            list1 = list1->next;
        } else {
            front = list2;
            list2 = list2->next;
        }
        front->next = nullptr;
        ListNode *back = front;
        while (1) {
            if (list1 == nullptr && list2 == nullptr) {
                break;
            } else if (list1 == nullptr) {
                back->next = list2;
                list2 = list2->next;
                back = back->next;
            } else if (list2 == nullptr) {
                back->next = list1;
                list1 = list1->next;
                back = back->next;
            } else {
                if (list1->val < list2->val) {
                    back->next = list1;
                    list1 = list1->next;
                    back = back->next;
                } else {
                    back->next = list2;
                    list2 = list2->next;
                    back = back->next;
                }
            }
            back->next = nullptr;
        }
        return front;
    }
};
