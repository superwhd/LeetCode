# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):

    def __init__(self, head):
        """
        @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
        :type head: ListNode
        """
        self.head = head
        length = 0
        while head:
            head = head.next
            length += 1
        self.length = length
        

    def getRandom(self):
        """
        Returns a random node's value.
        :rtype: int
        """
        n = random.randint(0, self.length - 1)
        p = self.head
        while n:
            n -= 1
            p = p.next
        return p.val
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()
