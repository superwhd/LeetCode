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
    ListNode *detectCycle(ListNode *head) {
        ListNode *p = head, *q = head;
        auto next = [] (ListNode *x) {
            if (!x) {
                return x;
            }
            return x->next;
        };
        while (p && q) {
            p = next(p);
            q = next(q);
            q = next(q);
            if (p && q && p == q) {
                break;
            }
        }
        if (!p || !q) {
            return nullptr;
        }
        p = head;
        while (p && q) {
            if (p == q) {
                return p;
            }
            p = next(p);
            q = next(q);
        }
        return nullptr;
    }
};
