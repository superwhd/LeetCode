class  Solution(object):

    def  __init__(self, nums):
        """
        
        :type nums: List[int]
        :type size: int
        """
        self.a =  nums
        self.to =  range(0, len(nums))
        self.n =  len(nums)

    def  reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        b =  [0] *  self.n
        for  i in  xrange(self.n):
            b[self.to[i]] =  self.a[i]
        self.a =  b
        self.to =  range(self.n)
        return  self.a
        

    def  shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        for  i in  xrange(self.n -  1):
            pos =  random.randint(i, self.n -  1)
            self.to[i], self.to[pos] =  self.to[pos], self.to[i]
            self.a[i], self.a[pos] =  self.a[pos], self.a[i]
        return  self.a


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
