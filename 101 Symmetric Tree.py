# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class  Solution(object):
    def  isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def  dfs(p, q):
            if  not  p and  not  q:
                return  True
            if  (p and  not  q) or  (q and  not  p):
                return  False
            if  p.val !=  q.val:
                return  False
            return  dfs(p.left, q.right) and  dfs(p.right, q.left)
        if  not  root:
            return  True
        return  dfs(root.left, root.right)
        
