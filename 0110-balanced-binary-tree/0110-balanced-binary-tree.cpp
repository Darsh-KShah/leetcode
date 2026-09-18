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
    int sol(TreeNode* node) {
        if(node == NULL) return 0;

        int l = sol(node->left);
        int r = sol(node->right);

        if(abs(l - r) > 1 or l == - 1 or r == -1) return -1;

        return max(l, r) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return sol(root) != -1;
    }
};