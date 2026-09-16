/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};

        vector<vector<int>> res;

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);

        vector<int> temp = {};

        while(!q.empty()) {
            if(q.front()) {
                TreeNode* cur = q.front();

                q.pop();

                temp.push_back(cur->val);

                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            } else {
                q.pop();

                res.push_back(temp);

                if(!q.empty()) q.push(nullptr);

                temp = {};
            }
        }

        return res;
    }
};