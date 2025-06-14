/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {

    public ListNode partition(ListNode head, int x) {
        ListNode less = null;
        ListNode backLess = null;
        ListNode rest = null;
        ListNode backRest = null;
        while (head != null) {
            if (head.val < x) {
                if (less == null) {
                    less = head;
                    backLess = head;
                    head = head.next;
                    backLess.next = null;
                    continue;
                }
                backLess.next = head;
                backLess = backLess.next;
                head = head.next;
                backLess.next = null;
            } else {
                if (rest == null) {
                    rest = head;
                    backRest = head;
                    head = head.next;
                    backRest.next = null;
                    continue;
                }
                backRest.next = head;
                backRest = backRest.next;
                head = head.next;
                backRest.next = null;
            }
        }
        if (backLess == null) return rest;
        if (backRest == null) return less;
        // Merge lists
        backLess.next = rest;
        return less;
    }
}
