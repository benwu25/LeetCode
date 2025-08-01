
// Definition for singly-linked list.
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
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        ListNode *res;
        if (list1->val <= list2->val) {
            res = new ListNode(list1->val);
            list1 = list1->next;
        } else {
            res = new ListNode(list2->val);
            list2 = list2->next;
        }
        ListNode *back = res;
        while (list1 || list2) {
            if (!list1 || list2 && list2->val <= list1->val) {
                back->next = new ListNode(list2->val);
                list2 = list2->next;
            } else if (!list2 || list1 && list1->val <= list2->val) {
                back->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            back = back->next;
        }
        return res;
    }
};
