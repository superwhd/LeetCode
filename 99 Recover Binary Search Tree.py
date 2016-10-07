# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead
            .
        """
    
        nodes = [None, None]
        def sol():
            global last
            global lastlast
            last = lastlast = None
            
            def dfs(x):
                global last
                global lastlast
                if not x:
                    return
                dfs(x.left)
                if not nodes[0] and last and last.val > x.val:
                    if not lastlast or lastlast.val < last.val:
                        nodes[0] = last
                if last and last.val < x.val:
                    if lastlast and lastlast.val > last.val:
                        nodes[1] = last
                lastlast = last
                last = x
                dfs(x.right)
                
            dfs(root)
            if lastlast and lastlast.val > last.val:
                nodes[1] = last
        
        sol()
        node1, node2 = nodes
        if node1 and node2:
            node1.val, node2.val = node2.val, node1.val
