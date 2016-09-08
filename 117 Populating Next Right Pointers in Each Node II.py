# Definition for binary tree with next pointer.
# class TreeLinkNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class  Solution(object):
    def  connect(self, root):
        """
        :type root: TreeLinkNode
        :rtype: nothing
        """
        if  not  root:
            return  
        parent =  root
        while  parent:
            p =  first =  None
            while  parent:
                if  parent.left:
                    if  not  p:
                        p =  parent.left
                        first =  p
                    else :
                        p.next =  parent.left
                        p =  p.next
                if  parent.right:
                    if  not  p:
                        p =  parent.right
                        first =  p
                    else :
                        p.next =  parent.right
                        p =  p.next
                parent =  parent.next
            parent =  first
        
    
