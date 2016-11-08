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
    ListNode* reverseList(ListNode* head) {
        ListNode *p = head, *last = nullptr;
        while (p) {
            ListNode *next = p->next;
            p->next = last;
            last = p;
            p = next;
        }
        return last;
    }
};
