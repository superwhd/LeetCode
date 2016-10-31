# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        ans = 0
        dic = {}
        dic[0] = 1
        global ans
        def dfs(x, now):
            global ans
            if not x:
                return
            now += x.val
            if (now - sum) in dic:
                ans += dic[now - sum]
            if not now in dic:
                dic[now] = 0
            dic[now] += 1
            dfs(x.left, now)
            dfs(x.right, now)
            dic[now] -= 1
        
        dfs(root, 0)
        return ans
