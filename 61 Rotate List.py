# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class  Solution:
    def  rotateRight(self, head, k):
        if  not  head:
            return  None
        dumbHead =  ListNode(1)
        dumbHead.next =  head
        length =  0
        p =  head
        last =  None
        while  p:
            last =  p
            p =  p.next
            length +=  1
        k %=  length
        if  not  k:
            return  head
        length -=  k
        p =  dumbHead
        while  length:
            p =  p.next
            length -=  1
        newHead =  p.next
        p.next =  None
        last.next =  head
        return  newHead
        
