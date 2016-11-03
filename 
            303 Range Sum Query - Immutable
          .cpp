class NumArray {
public:
    NumArray(vector<int> &nums) {
        sum = move(nums);
        for (int i = 1; i < sum.size(); i++) {
            sum[i] += sum[i - 1];
        }
        for (int i = 0; i < sum.size(); i++) {
            cout << sum[i] << endl;
        }
    }

    int sumRange(int i, int j) {
        return sum[j] - (i ? sum[i - 1] : 0);
    }
private:
    vector<int> sum;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
