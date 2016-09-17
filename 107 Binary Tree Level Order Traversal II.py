# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class  Solution(object):
    def  levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        ans =  []
        def  dfs(x, dep):
            if  not  x:
                return  
            if  len(ans) ==  dep:
                ans.append([x.val])
            else :
                ans[dep].append(x.val)
            dfs(x.left, dep +  1)
            dfs(x.right, dep +  1)
        
        dfs(root, 0)
        return  ans[::- 1]
