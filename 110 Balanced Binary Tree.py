# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class  Solution(object):
    def  isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def  dfs(x):
            if  not  x:
                return  True, 0
            left, right =  dfs(x.left), dfs(x.right)
            if  not  left[0] or  not  right[0] or  abs(left[1] -  right[1]) >  1:
                return  False, 0
            return  True, max(left[1], right[1]) +  1
            
        return  dfs(root)[0]
