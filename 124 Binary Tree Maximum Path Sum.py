# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class  Solution(object):
    def  maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        ans =  [root.val]
        def  dfs(x, s):
            if  not  x:
                return  0
            s +=  x.val
            left =  max(dfs(x.left, s), 0)
            right =  max(dfs(x.right, s), 0)
            ans[0] =  max(ans[0], s +  left, s +  right, left +  right +  x.val)
            return  max(left, right) +  x.val
        
        dfs(root, 0)
        return  ans[0]
