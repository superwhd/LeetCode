class Solution {
public:
    bool isPowerOfFour(int num) {
        int cnt = 0;
        while (num > 0 && !(num & 1)) {
            cnt++;
            num >>= 1;
        }
        return num == 1 && !(cnt & 1);
    }
};