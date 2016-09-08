# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class  Solution(object):
    def  rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        now =  root
        ans =  []
        def  dfs(dep, x):
            if  not  x:
                return 
            if  len(ans) <  dep:
                ans.append(x.val)
            if  x.right:
                dfs(dep +  1, x.right)
            if  x.left:
                dfs(dep +  1, x.left)
        dfs(1, root)
        return  ans
