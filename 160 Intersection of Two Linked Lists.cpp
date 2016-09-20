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
    ListNode * getIntersectionNode(ListNode * headA, ListNode * headB) {
        int lenA =  getLen(headA), lenB =  getLen(headB);
        if  (lenA <  lenB) {
            swap(lenA, lenB);
            swap(headA, headB);
        }
        while  (lenA >  lenB) {
            headA =  headA-> next;
            lenA-- ;
        }
        while  (headA !=  headB) {
            headA =  headA-> next;
            headB =  headB-> next;
        }
        return  headA;
    }
private:
    int getLen(ListNode * head) {
        int s =  0;
        while  (head) {
            head =  head-> next;
            s++ ;
        }
        return  s;
    }
};
