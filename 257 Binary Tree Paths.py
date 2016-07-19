# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # @param {TreeNode} root
    # @return {string[]}
    def binaryTreePaths(self, root):
        ans = []
        def dfs(x, path):
            if not x.left and not x.right:
                ans.append(path)
                return
            if x.left:
                dfs(x.left, path + '->' + str(x.left.val))
            if x.right:
                dfs(x.right, path + '->' + str(x.right.val))
        if root:
            dfs(root, str(root.val))
        return ans
            