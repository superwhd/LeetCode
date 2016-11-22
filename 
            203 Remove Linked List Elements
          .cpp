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
    ListNode* removeElements(ListNode* head, int val) {
        auto dumbHead = new ListNode(0);
        dumbHead->next = head;
        for (auto p = dumbHead; p; p = p->next) {
            while (p->next && p->next->val == val) {
                auto q = p->next;
                p->next = p->next->next;
            }
        }
        head = dumbHead->next;
        delete dumbHead;
        return head;
    }
};
