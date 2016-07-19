/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2)
            return NULL;
        ListNode *p1 = l1, *p2 = l2, *lans = new ListNode(0), *p3;
        p3 = lans;
        int c = 0;
        while (p1 || p2 || c) {
            int s = c;
            if (p1) {
                s += p1 -> val;
                p1 = p1 -> next;
            }
            if (p2) {
                s += p2 -> val;
                p2 = p2 -> next;
            }
            c = s / 10;
            p3 -> val = s % 10;
            if (p1 || p2 || c) {
                p3 -> next = new ListNode(0);
                p3 = p3 -> next;
            }
        }
        return lans;
    }
};