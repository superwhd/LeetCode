/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        function<int(TreeNode *, int)> dfs = [&] (TreeNode *x, int prevRank) {
            if (!x) {
                return 0;
            }  
            int leftSize = dfs(x->left, prevRank);
            int rank = prevRank + leftSize + 1;
            if (rank == k) {
                ans = x->val;
            }
            int rightSize = dfs(x->right, rank);
            return leftSize + rightSize + 1;
        };
        dfs(root, 0);
        return ans;
    }
};
