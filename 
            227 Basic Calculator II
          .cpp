class Solution {
public:
    int calculate(string s) {
        auto it = s.begin();
        auto hasNext = [&] () { 
            while (it != end(s) && *it == ' ') {
                it++;
            }
            return it != end(s);
        };
        auto read = [&] () {
            while (it != end(s) && *it == ' ') {
                it++;
            }
            string s = "";
            if (isdigit(*it)) {
                while (it != end(s) && isdigit(*it)) {
                    s += *it;
                    it++;
                }
            } else {
                s += *it;
                it++;
            }
            return s;
        };
        vector<string> tokens;
        while (hasNext()) {
            tokens.push_back(read());
        }
        auto prec = [] (const string &op) {
            if (op == "*" || op == "/") {
                return 1;
            }  
            return 0;
        };
        auto calc = [] (const int &x, const string &op, const int &y) {
            if (op == "+") {
                return x + y;
            } else if (op == "-") {
                return x - y;
            } else if (op == "*") {
                return x * y;
            } else if (op == "/") {
                return x / y;
            }
            return -212121;
        };
        function<int(vector<string>::iterator &, int)> eval = [&] (vector<string>::iterator &it, int pre) {
            auto lhs = stoi(*it);
            it++;
            while (it != end(tokens) && prec(*it) >= pre) {
                auto &op = *it;
                it++;
                auto nowPre = prec(op) + 1;
                auto rhs = eval(it, nowPre);
                lhs = calc(lhs, op, rhs);
            }
            return lhs;
        };
        auto tokensIt = begin(tokens);
        return eval(tokensIt, -1);
    }
};
