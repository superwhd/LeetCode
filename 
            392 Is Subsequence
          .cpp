class Solution {
public:
    bool isSubsequence(string s, string t) {
        int top = 0;
        for (auto c : t) {
            if (c == s[top]) 
                top++;
            if (top == s.size())
                return true;
        }
        return top == s.size();
    }
};
