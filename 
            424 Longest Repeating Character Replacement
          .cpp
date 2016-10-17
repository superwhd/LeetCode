#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt[26];
        int n = s.size();
        for (int i = 0; i < 26; i++)
            cnt[i].resize(s.size() + 1);
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < 26;j ++)
                cnt[j][i] = cnt[j][i - 1];
            cnt[s[i - 1] - 'A'][i] ++;
        }
        int ans = 0;
        for (int c = 0; c < 26; c++) {
            int j = 1;
            for (int i = 0; i <= n; i++) {
                while (j <= n && cnt[c][j] - cnt[c][i] + k >= j - i)
                    j++;
                ans = max(ans, j - i - 1);
            }
        }
        return ans;

    }
};
