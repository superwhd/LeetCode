class Solution {
public:
    string reverseString(string s1) {
        reverse(s1.begin(), s1.end());
        return s1;
    }
};