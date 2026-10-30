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
    int dfs(TreeNode* node) {
        if(node == NULL) return 0;

        if(node->left == NULL && node->right == NULL) return 1;

        int l = (node->left) ? dfs(node->left) : 1e5 + 1;
        int r = (node->right) ? dfs(node->right) : 1e5 + 1;

        return min(l, r) + 1;
    }

    int minDepth(TreeNode* root) {
        return dfs(root);
    }
};