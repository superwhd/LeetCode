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
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        // if (!root->left && !root->right) {
        //     return 1;
        // }
        auto rightLength = [] (TreeNode *x) {
            auto len = 0;
            while (x) {
                x = x->right;
                len++;
            }
            return len;
        };
        int l = rightLength(root->left), r = rightLength(root->right);
        // cout << l << " " << r << endl;
        if (l > r) {
            return 1 + (1 << l) - 1 + countNodes(root->right);
        } else {
            return 1 + (1 << r) - 1 + countNodes(root->left);
        }
    }
};
