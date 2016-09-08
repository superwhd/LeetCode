# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class  Solution(object):
    def  lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        def  dfs(root, p, q):
            if  not  root:
                return  None
            if  root ==  p or  root ==  q:
                return  root
            left =  dfs(root.left, p, q)
            right =  dfs(root.right, p, q)
            if  left and  right:
                return  root
            return  left if  left else  right
        return  dfs(root, p, q)
