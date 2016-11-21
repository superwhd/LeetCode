class Solution {
public:
    bool isValidSerialization(string preorder) {
        auto it = begin(preorder);
        auto read = [&] () {
            string str;
            for (; it != end(preorder) && (*it) != ','; it++) {
                str += *it;
            }
            if (it != end(preorder)) {
                it++;
            }
            return str;
        };
        
        function<bool()> dfs = [&] () {
            if (it == end(preorder)) {
                return false;
            }
            for (int i = 0; i < 2; i++) {
                auto val = read();
                if (val == "#") {
                    continue;
                } else {
                    if (!dfs()) {
                        return false;
                    }
                }
            }
            return true;
        };
        if (read() != "#") {
            if (!dfs()) {
                return false;
            }
        }
        return it == end(preorder);
    }
};
