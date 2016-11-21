/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        int head = 0;
        vector<TreeNode *> q;
        q.push_back(root);
        while (head < q.size()) {
            auto s = q[head++];
            if (!s) {
                continue;
            }
            for (auto v : {s->left, s->right}) {
                q.push_back(v);
            }
        }
        int r;
        for (r = q.size() - 1; r >= 0; r--) {
            if (q[r]) {
                break;
            }
        }
        for (int i = 0; i <= r; i++) {
            auto node = q[i];
            if (node) {
                res += to_string(node->val);
            } else {
                res += "n";
            }
            res += ",";
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        queue<TreeNode *> q;
        int pos = 0;
        auto read = [&] () {
            string res;
            for (; pos < data.size() && data[pos] != ','; pos++) {
                res.push_back(data[pos]);
            }
            pos++;
            return res;
        };
        q.push(new TreeNode(stoi(read())));
        TreeNode *root = q.front();
        while (!q.empty() && pos < data.size()) {
            auto s = q.front();
            q.pop();
            for (auto v : {&(s->left), &(s->right)}) {
                auto val = string("n");
                if (pos < data.size()) {
                    val = read();
                } 
                if (val == "n") {
                    *v = nullptr;
                } else {
                    *v = new TreeNode(stoi(val));
                    q.push(*v);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
