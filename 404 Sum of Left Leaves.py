# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class  Solution(object):
    def  sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def  dfs(x, fa):
            if  not  x:
                return  0
            val =  0
            if  not  x.left and  not  x.right and  fa and  fa.left ==  x:
                val =  x.val
            return  val +  dfs(x.left, x) +  dfs(x.right, x)
        return  dfs(root, None)
