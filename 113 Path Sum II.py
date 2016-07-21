# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution(object):
        
    def dfs(self, now, now_list, sum):
        def isLeaf(t):
            return not t.left and not t.right
        if not now:
            return 
        now_list.append(now.val)
        if now.val == sum and isLeaf(now):
            self.ans.append(now_list[:])
        self.dfs(now.left, now_list, sum - now.val)
        self.dfs(now.right, now_list, sum - now.val)
        now_list.pop()
            
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        self.ans = []
        self.dfs(root, [], sum)
        return self.ans