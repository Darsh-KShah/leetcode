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
        if(node->left == NULL && node->right == NULL) return 1;

        int l = (node->left) ? dfs(node->left) : INT_MAX;
        int r = (node->right) ? dfs(node->right) : INT_MAX;

        return min(l, r) + 1;
    }

    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        return dfs(root);
    }
};