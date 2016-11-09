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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        function<int(ListNode *)> getLen = [] (ListNode *x) {
            int s = 0;
            while (x) {
                s++;
                x = x->next;
            }
            return s;
        };
        int len = getLen(head);
        auto getKey = [&] () {
            int k = rand() % len;
            auto p = head;
            while (k--) {
                p = p->next;
            }
            return p->val;
        };
        int key = getKey();
        ListNode *lHead = nullptr, *rHead = nullptr, *mHead = nullptr;
        auto add = [] (ListNode *&h, ListNode *p) {
            if (!h) {
                h = p;
                h->next = nullptr;
            } else {
                p->next = h;
                h = p;
            }
        };
        ListNode *next;
        for (auto p = head; p; p = next) {
            next = p->next;
            if (p->val < key) {
                add(lHead, p);
            } else if (p->val > key) {
                add(rHead, p);
            } else {
                add(mHead, p);
            }
        }
        lHead = sortList(lHead);
        rHead = sortList(rHead);
        auto p = lHead;
        if (lHead) {
            for (; p->next; p = p->next);
            p->next = mHead;
        }
        for (p = mHead; p->next; p = p->next);
        p->next = rHead;
        return lHead ? lHead : mHead;
    }
};
