class Solution {
public:
    int calculate(string s) {
        str =  s;
        index =  0;
        return  parse();
    }
private:
    int parse() {
        if  (end())
            return  0;
        int res =  parseUnit();
        while  (! end() &&  peek() !=  ')') {
            int op =  peek() ==  '+' ? 1 : -1;
            next();
            res +=  op *  parseUnit();
        }
        return  res;
    }
    int parseUnit() {
        int res =  0;
        if  (peek() ==  '(') {
            next();
            res =  parse();
            next();
        } else  if (isNumber(peek())) {
            while  (! end() &&  isNumber(peek())) {
                res =  res *  10 +  peek() -  '0';
                next();
            }
        } 
        return  res;
    }
    bool isNumber(char ch) {
        return  ch >=  '0' &&  ch <=  '9';
    }
    char peek() {
        while  (! end() &&  (str[index] ==  ' ' ||  str[index] ==  '\t'))
            index++ ;
        return  str[index];
    }
    void next() {
        index++ ;
    }
    bool end() {
        while  (index <  str.size() &&  (str[index] ==  ' ' ||  str[index] ==  '\t'))
            index++ ;
        return  index ==  str.size();
    }
    int index;
    string str;

};

