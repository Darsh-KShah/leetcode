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
    void sol(vector<int> &res, TreeNode* node) {
        if(node == NULL) return;

        sol(res, node->left);

        res.push_back(node->val);

        sol(res, node->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;

        sol(res, root);

        return res;
    }
};