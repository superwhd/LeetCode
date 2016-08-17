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
    ListNode*  swapPairs(ListNode*  head) {
        ListNode * p, * q, * first, * last, * next;
        if  (! head) {
            return  head;
        }
        if  (head-> next) {
            first =  head-> next;
        } else  {
            first =  head;
        }
        last =  NULL;
        for  (p =  head, q =  head-> next; p &&  q;) {
            if  (last) {
                last-> next =  q;
            }
            next =  q-> next;
            q-> next =  p;
            p-> next =  next;
            last =  p;
            p =  next;
            if  (p) {
                q =  p-> next;
            }
        }
        return  first;
    }
};
