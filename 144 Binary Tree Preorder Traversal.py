# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ans = []
        def dfs(x):
            if not x:
                return 
            ans.append(x.val)
            dfs(x.left)
            dfs(x.right)
        
        dfs(root)
        return ans
