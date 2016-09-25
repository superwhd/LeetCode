class  Solution(object):
    def  reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        if  not  people:
            return  []
        n =  len(people)
        ans =  [(- 1, - 1)] *  n
        for  times in  xrange(n):
            minx =  (9999999, 9999999)
            minid =  - 1
            for  i, t in  enumerate(people):
                if  t <  minx:
                    minx =  t
                    minid =  i
            h, kk =  minx
            k =  kk
            i =  0
            while  k:
                if  ans[i][0] ==  - 1 or  ans[i][0] >=  h:
                    k -=  1
                i +=  1
            while  ans[i][0] !=  - 1:
                i +=  1
            ans[i] =  h, kk
            # print i, h, kk
            people[minid] =  99999999, 99999999
        return  ans
