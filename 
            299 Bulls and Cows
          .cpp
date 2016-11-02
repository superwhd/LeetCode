class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        string s1, s2;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                s1.push_back(secret[i]);
                s2.push_back(guess[i]);
            }
        }
        sort(begin(s1), end(s1));
        sort(begin(s2), end(s2));
        int i = 0, j = 0;
        while (i < s1.size() && j < s2.size()) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
                cows++;
            } else if (s1[i] < s2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};
