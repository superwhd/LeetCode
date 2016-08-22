# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class  Solution(object):
    def  partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        smallerHead =  largerHead =  smallerTail =  largerTail =  None
        now =  head
        while  now:
            if  now.val <  x:
                if  not  smallerHead:
                    smallerHead =  smallerTail =  now
                else :
                    smallerTail.next =  now
                    smallerTail =  now
            else :
                if  not  largerHead:
                    largerHead =  largerTail =  now
                else :
                    largerTail.next =  now
                    largerTail =  now
            now =  now.next
        if  smallerTail:
            smallerTail.next =  largerHead
            head =  smallerHead
        else :
            head =  largerHead
        if  largerTail:
            largerTail.next =  None
        return  head
