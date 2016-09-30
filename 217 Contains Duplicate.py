class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        counter = collections.Counter(nums)
        arr = [item[1] > 1 for item in counter.items()]
        return sum(arr) > 0
