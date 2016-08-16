class  Solution(object):
    def  findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if  not  words:
            return  []
        uniqueWords =  list(set(words))
        dic =  dict([(word, i) for  i, word in  enumerate(uniqueWords)])
        need =  [(sum([1 for  word in  words if  word ==  uniqueWord])) for  uniqueWord in  uniqueWords]
        perLen =  len(words[0])
        wordCnt =  len(words)
        ans =  []
        for  remainder in  xrange(perLen):
            lst =  []
            for  i in  xrange(0, (len(s) -  remainder) /  perLen):
                subs =  s[i *  perLen +  remainder : ((i +  1) *  perLen +  remainder)]
                if  subs in  dic:
                    lst.append(dic[subs])
                else :
                    lst.append(- 1)
            myset =  [0] *  len(uniqueWords)
            cnt =  0
            for  i, num in  enumerate(lst):
                if  num !=  - 1:
                    myset[num] +=  1
                    if  myset[num] ==  need[num]:
                        cnt +=  1
                if  i >=  wordCnt:
                    numToDel =  lst[i -  wordCnt]
                    if  numToDel !=  - 1:
                        myset[numToDel] -=  1
                        if  myset[numToDel] +  1 ==  need[numToDel]:
                            cnt -=  1
                if  cnt ==  len(uniqueWords):
                    ans.append((i -  wordCnt +  1) *  perLen +  remainder)
        return  ans


