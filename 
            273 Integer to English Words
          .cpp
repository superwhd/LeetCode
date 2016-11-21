class Solution {
public:
    string numberToWords(int num) {
        vector<string> units{"", "Thousand", "Million", "Billion"};
        vector<string> digits{"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", 
            "Eighteen", "Nineteen"};
        vector<string> tys = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<int> nums;
        while (num) {
            nums.push_back(num % 1000);
            num /= 1000;
        }
        if (nums.empty()) {
            return "Zero";
        }
        string ans;
        auto readThreeDigits = [&] (int x) {
            string res;
            int first = x / 100, second = x / 10 % 10, third = x % 10;
            if (first) {
                res += digits[first] + " " + "Hundred";
            }
            if (second) {
                if (second == 1) {
                    if (res.size()) {
                        res += " ";
                    }
                    res += teens[third];
                } else {
                    if (res.size()) {
                        res += " ";
                    }
                    res += tys[second - 2];
                    if (third) {
                        res += " " + digits[third];
                    }
                }
            } else if (third) {
                if (res.size()) {
                    res += " ";
                }
                res += digits[third];
            }
            return res;
        };
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (ans.size() && nums[i]) {
                ans += " ";
            }
            ans += readThreeDigits(nums[i]);
            if (nums[i] && i) {
                ans += " " + units[i];
            }
        }
        return ans;
    }
};
