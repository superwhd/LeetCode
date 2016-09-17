# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class  Solution(object):
    def  generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        def  copyTree(root):
            if  not  root:
                return  None
            copiedRoot =  TreeNode(root.val)
            copiedRoot.left =  copyTree(root.left)
            copiedRoot.right =  copyTree(root.right)
            return  copiedRoot
            
        def  dfs(begin, end):
            if  begin >  end:
                return  [None]
            ans =  []
            for  i in  xrange(begin, end +  1):
                lefts =  dfs(begin, i -  1)
                rights =  dfs(i +  1, end)
                for  left in  lefts:
                    for  right in  rights:
                        root =  TreeNode(i)
                        root.left =  left
                        root.right =  right
                        ans.append(root)
            return  ans
        
        if  not  n:
            return  []
        return  dfs(1, n)

