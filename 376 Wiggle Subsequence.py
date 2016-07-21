class Solution(object):
    def wiggleMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2:
            return len(nums)
        diff = [(nums[i] - nums[i - 1]) for i in xrange(1, len(nums))]
        diff = [v for v in diff if v]
        ans = 0
        for i in xrange(1, len(diff)):
            ans += (diff[i] * diff[i - 1]) < 0
        return ans + (2 if len(diff) else 1)