# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        oddHead = oddTail = head
        evenHead = evenTail = None if head == None else head.next
        cnt = 0
        p = head
        while p:
            cnt += 1
            if cnt > 2:
                if cnt % 2 == 1:
                    oddTail.next = p
                    oddTail = p
                else:
                    evenTail.next = p
                    evenTail = p
            p = p.next
        if evenTail:
            evenTail.next = None
        if oddTail:
            oddTail.next = evenHead
        return oddHead
        
            