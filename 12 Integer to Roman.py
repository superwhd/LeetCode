class  Solution(object):
    def  intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        chars =  (('I', 'V', 'X'), ('X', 'L', 'C'), ('C', 'D', 'M'), ('M'))
        lst =  [ord(digit) -  ord('0') for  digit in  reversed(str(num))]
        res =  ''
        def  get(digit, char_of_this_digit):
            if  len(char_of_this_digit) ==  1:
                return  char_of_this_digit[0] *  digit
            if  not  digit:
                return  ''
            if  digit <=  3:
                return  char_of_this_digit[0] *  digit
            if  digit ==  4:
                return  char_of_this_digit[0] +  char_of_this_digit[1]
            if  digit <=  8:
                return  char_of_this_digit[1] +  (digit -  5) *  char_of_this_digit[0]
            return  char_of_this_digit[0] +  char_of_this_digit[2]

        for  i in  xrange(len(lst) -  1, - 1, - 1):
            res +=  get(lst[i], chars[i])
        return  res


