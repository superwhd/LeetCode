class AllOne(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.dic = {}
        self.lst = [sets.Set()]
        self.size = 0
        self.minValue = 0
        self.maxValue = 0
        
    def inc(self, key):
        """
        Inserts a new key <Key> with value 1. Or increments an existing key by 1.
        :type key: str
        :rtype: void
        """
        if not key in self.dic:
            self.dic[key] = 0
            self.size += 1
            self.minValue = 1
        self.dic[key] += 1
        value = self.dic[key]
        
        if value > 1:
            self.lst[value - 1].remove(key)
            if self.minValue == value - 1 and not len(self.lst[value - 1]):
                self.minValue = value
                
        self.maxValue = max(self.maxValue, value)
        if len(self.lst) <= value:
            self.lst.append(sets.Set())
        self.lst[value].add(key)
        
        

    def dec(self, key):
        """
        Decrements an existing key by 1. If Key's value is 1, remove it from the data structure.
        :type key: str
        :rtype: void
        """
        if not key in self.dic:
            return 
        self.dic[key] -= 1
        value = self.dic[key]
        if not value:
            del self.dic[key]
            self.size -= 1
        else:
            self.lst[value].add(key)
            self.minValue = min(self.minValue, value)
        self.lst[value + 1].remove(key)
        if self.maxValue == value + 1 and not len(self.lst[value + 1]):
            self.maxValue -= 1
        

    def getMaxKey(self):
        """
        Returns one of the keys with maximal value.
        :rtype: str
        """
        if not self.size:
            return ''
        for e in self.lst[self.maxValue]:
            return e

    def getMinKey(self):
        """
        Returns one of the keys with Minimal value.
        :rtype: str
        """
        if not self.size:
            return ''
        for e in self.lst[self.minValue]:
            return e


# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc(key)
# obj.dec(key)
# param_3 = obj.getMaxKey()
# param_4 = obj.getMinKey()
