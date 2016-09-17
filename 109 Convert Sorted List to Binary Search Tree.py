# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class  Solution(object):
    def  sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        length =  0
        p =  head
        while  p:
            p =  p.next
            length +=  1
        
        def  getKth(begin, k):
            k -=  1
            while  k >  0:
                begin =  begin.next
                k -=  1
            return  begin
            
        def  build(begin, n):
            if  n <=  0:
                return  None
            mid =  (n +  1) >>  1
            midListNode =  getKth(begin, mid)
            rootNode =  TreeNode(midListNode.val)
            rootNode.left =  build(begin, mid -  1)
            rootNode.right =  build(midListNode.next, n -  mid)
            return  rootNode
        
        return  build(head, length)
