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
    void reorderList(ListNode* head) {
        if (!head) {
            return ;
        }
        auto getLen = [] (ListNode *x) {
            int s = 0;
            for (; x; x = x->next) {
                s++;
            }
            return s;
        };
        int len = getLen(head);
        int halflen = (len + 1) >> 1;
        ListNode *head1 = head, *head2 = head;
        for (int i = 0; i + 1 < halflen; i++) {
            head2 = head2->next;
        }
        ListNode *next = head2->next;
        head2->next = nullptr;
        head2 = next;
        auto reverse = [] (ListNode *x) {
            ListNode *newHead = nullptr;
            ListNode *next;
            for (; x; x = next) {
                next = x->next;
                x->next = newHead;
                newHead = x;
            }
            return newHead;
        };
        head2 = reverse(head2);
        ListNode *p = head1, *q = head2;
        ListNode *newHead = nullptr, *newTail = nullptr;
        int cnt = 0;
        while (p) {
            if (!newHead) {
                newHead = newTail = p;
                p = p->next;
            } else {
                newTail->next = p;
                newTail = p;
                p = p->next;
            }
            if (q) {
                newTail->next = q;
                newTail = q;
                q = q->next;
            }
        }
        newTail->next = nullptr;
    }
};
