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
    int maxSum(TreeNode* node, int &res) {
        if(node == NULL) return 0;

        int l = max(0, maxSum(node->left, res));
        int r = max(0, maxSum(node->right, res));

        res = max(res, l + r + node->val);

        return max(l, r) + node->val;
    }

    int maxPathSum(TreeNode* root) {
        int sum = root->val;

        maxSum(root, sum);

        return sum;
    }
};