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
    bool isPalindrome(ListNode* head) {
        if (!head) {
            return true;
        }
        auto getLen = [] (ListNode *x) {
            int s = 0;
            while (x) {
                s++;
                x = x->next;
            }
            return s;
        };
        int len = getLen(head);
        auto get = [] (ListNode *x, int k) {
            while (k--) {
                x = x->next;
            }
            return x;
        };
        if (len == 1) {
            return true;
        }
        ListNode *h1 = head, *h2 = get(head, (len + 1) / 2 - 1);
        auto next = h2->next;
        h2->next = nullptr;
        h2 = next;
        auto reversed = [] (ListNode *x) {
            ListNode *newHead = nullptr;
            while (x) {
                auto next = x->next;
                x->next = newHead;
                newHead = x;
                x = next;
            }
            return newHead;
        };
        h2 = reversed(h2);
        for (; h1 && h2; h1 = h1->next, h2 = h2->next) {
            if (h1->val != h2->val) {
                return false;
            }
        }
        return true;
    }
};
