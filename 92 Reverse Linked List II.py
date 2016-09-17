# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class  Solution(object):
    def  reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        def  findKth(head, k):
            while  k:
                k -=  1
                head =  head.next
            return  head
        
        dumbHead =  ListNode(0)
        dumbHead.next =  head
        begin =  findKth(dumbHead, m -  1)
        end =  findKth(dumbHead, n)
        endOfEnd =  end.next
        newEnd =  begin.next
        newHead =  end
        p =  begin.next.next
        last =  begin.next
        while  p !=  endOfEnd:
            next =  p.next
            p.next =  last
            last =  p
            p =  next
        begin.next =  newHead
        newEnd.next =  endOfEnd
        return  dumbHead.next
