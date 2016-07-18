# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        def helpBuildTree(pre, lpre, rpre, ino, lin, rin):
            if lpre == rpre:
                return None
            root = TreeNode(pre[lpre])
            root_index = ino.index(root.val)
            left_size = root_index - lin
            root.left = helpBuildTree(pre, lpre + 1, lpre + 1 + left_size, ino, lin, lin + left_size)
            root.right = helpBuildTree(pre, lpre + 1 + left_size, rpre, ino, lin + left_size + 1, rin)
            return root
            
        return helpBuildTree(preorder, 0, len(preorder), inorder, 0, len(inorder))
        