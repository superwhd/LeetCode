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
    int rob(TreeNode* root) {
        unordered_map<TreeNode *, array<int, 2>> f;
        function<void(TreeNode *x)> dfs = [&] (TreeNode *x) {
            if (!x) {
                return ;
            }  
            f[x][0] = 0;
            f[x][1] = x->val;
            for (auto v : {x->left, x->right}) {
                if (v) {
                    dfs(v);
                    f[x][0] += max(f[v][0], f[v][1]);
                    f[x][1] += f[v][0];
                }
            }
        };
        if (!root) {
            return 0;
        }
        dfs(root);
        return max(f[root][0], f[root][1]);
    }
};
