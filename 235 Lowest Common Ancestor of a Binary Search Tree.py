# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        def dfs(x, p, q):
            if not x:
                return None
            if x.val == p.val or x.val == q.val:
                return x
            p_choice = x.right if p.val > x.val else x.left
            q_choice = x.right if q.val > x.val else x.left
            if p_choice != q_choice:
                return x
            return dfs(p_choice, p, q)
        return dfs(root, p, q)
