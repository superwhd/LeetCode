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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        using HeapNode = pair<int, ListNode*>;
        priority_queue<HeapNode> heap;
        for (auto &lis : lists) {
            if (lis)
                heap.push(make_pair(-lis->val, lis));
        }
        ListNode *dummyHead, *tail;
        ListNode tmpNode(0);
        dummyHead = tail = &tmpNode; 
        while (!heap.empty()) {
            HeapNode node = heap.top();
            heap.pop();
            tail->next = node.second;
            tail = tail->next;
            if (node.second->next) {
                ListNode *next = node.second->next;
                heap.push(make_pair(-next->val, next));
            }
        }
        return dummyHead->next;
    }
};