# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class  Solution(object):
    def  levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        ans =  []
        if  not  root:
            return  ans
        q =  [root]
        while  len(q):
            q_ =  []
            ans.append([t.val for  t in  q])
            for  node in  q:
                if  node.left:
                    q_.append(node.left)
                if  node.right:
                    q_.append(node.right)
            q =  q_
        return  ans
