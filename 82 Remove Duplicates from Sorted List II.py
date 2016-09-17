# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class  Solution(object):
    def  deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dumbHead =  ListNode(0)
        dumbHead.next =  head
        last =  dumbHead
        p =  head
        while  p:
            q =  p
            while  q and  q.val ==  p.val:
                q =  q.next
            if  q ==  p.next:
                last.next =  p
                last =  p
            p =  q
        last.next =  None
        return  dumbHead.next
        
