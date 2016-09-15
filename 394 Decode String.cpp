class Solution {
public:
    string decodeString(string s) {
        str =  s;
        index =  0;
        return  parse();
    }
private:
    string parse() {
        string res;
        while  (! end() &&  peek() !=  ']') {
            if  (isNumber(peek()))
                res +=  parseRepeat();
            else  
                res +=  parseStr();
        }
        return  res;
    }
    string parseRepeat() {
        string res;
        int s =  0;
        while  (! end() &&  isNumber(peek())) {
            s *=  10;
            s +=  peek() -  '0';
            next();
        }
        next();
        string toRepeat =  parse();
        next();
        while  (s-- )
            res +=  toRepeat;
        return  res;
    }
    string parseStr() {
        string res;
        while  (! end()) {
            char ch =  peek();
            if  (! isNumber(ch) &&  ch !=  ']')
                res +=  ch;
            else  break ;
            next();
        }
        return  res;
    }
    bool isNumber(char ch) {
        return  ch >=  '0' &&  ch <=  '9';
    } 
    bool end() {
        return  index ==  str.size();
    }
    char peek() {
        return  str[index];
    }
    void next() {
        index++ ;
    }
    int index;
    string str;
};
