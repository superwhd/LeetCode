# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class  Solution(object):
    def  reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        def  reverse(begin, end):
            last =  None
            now =  begin
            while  now !=  end:
                next =  now.next
                if  last:
                    now.next =  last
                last =  now
                now =  next
            return  last, begin
            
        cnt =  0
        now =  begin =  head
        lastTail =  None
        while  now:
            cnt +=  1
            next =  now.next
            if  cnt ==  k:
                end =  now.next
                newHead, newTail =  reverse(begin, end)
                if  not  lastTail:                    
                    head =  newHead
                else :                    
                    lastTail.next =  newHead
                lastTail =  newTail
                begin =  end
                next =  end
                cnt =  0
            now =  next
        if  cnt <  k and  lastTail:
            lastTail.next =  begin
        return  head
                
