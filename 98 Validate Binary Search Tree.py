# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class  Solution(object):
    def  isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def  dfs(x):
            if  not  x:
                return  (True, None, None)
            triLeft =  dfs(x.left)
            triRight =  dfs(x.right)
            if  not  triLeft[0] or  not  triRight[0]:
                return  False, None, None
            if  not  (triLeft[2] is  None) and  triLeft[2] >=  x.val:
                return  False, None, None
            if  not  (triRight[1] is  None) and  triRight[1] <=  x.val:
                return  False, None, None
            minVal =  maxVal =  x.val
            if  x.left:
                minVal =  triLeft[1]
            if  x.right:
                maxVal =  triRight[2]
            return  True, minVal, maxVal
        return  dfs(root)[0]
