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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        function<TreeNode*(int, int, int, int)> build = [&] (int l1, int r1, int l2, int r2) {
            if (l1 > r1) {
                return (TreeNode*)(nullptr);
            }
            int rootVal = postorder[r2];
            int mid;
            for (int i = l1; i <= r1; i++) {
                if (inorder[i] == rootVal) {
                    mid = i;
                    break;
                }
            }
            int leftSize = mid - l1, rightSize = r1 - mid;
            auto root = new TreeNode(rootVal);
            root->left = build(l1, mid - 1, l2, l2 + leftSize - 1);
            root->right = build(mid + 1, r1, l2 + leftSize, r2 - 1);
            return root;
        };
        return build(0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};
