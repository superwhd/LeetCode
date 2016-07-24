# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution(object):
    ans = 0
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def dfs(x, sum):
            if not x:
                return 
            if not x.left and not x.right:
                self.ans += sum
                return 
            if x.left:
                dfs(x.left, sum * 10 + x.left.val)
            if x.right:
                dfs(x.right, sum * 10 + x.right.val)
        if root:
            dfs(root, root.val)
        return self.ans