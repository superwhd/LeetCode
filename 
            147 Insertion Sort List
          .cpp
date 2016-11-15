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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dumbHead = new ListNode(-0x7fffffff - 1);
        dumbHead->next = nullptr;
        auto insert = [&] (ListNode *t) {
            auto p = dumbHead;
            for (; p->next; p = p->next) {
                if (p->next->val > t->val) {
                    t->next = p->next;
                    p->next = t;
                    return ;
                }
            }  
            p->next = t;
        };
        for (ListNode *p = head, *next; p; p = next) {
            next = p->next;
            p->next = nullptr;
            insert(p);
        }
        auto res = dumbHead->next;
        delete dumbHead;
        return res;
    }
};
