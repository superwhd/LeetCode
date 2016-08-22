# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class  Solution(object):
    def  sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        def  init(nums, l, r):
            if  l >  r:
                return  None
            mid =  (l +  r) >>  1
            p =  TreeNode(nums[mid])
            p.left =  init(nums, l, mid -  1)
            p.right =  init(nums, mid +  1, r)
            return  p
        return  init(nums, 0, len(nums) -  1)
