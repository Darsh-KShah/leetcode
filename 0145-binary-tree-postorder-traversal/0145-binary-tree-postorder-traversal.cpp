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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;

        if(root == NULL) return res;

        stack<TreeNode*> st;
        TreeNode* cur = root;

        while(cur != NULL or !st.empty()) {
            while(cur != NULL) { // all L
                st.push(cur);

                cur = cur->left;
            }

            TreeNode* node = st.top()->right;

            if(node != NULL) cur = node; // go R to again go all L
            else { // LR done go to root
                node = st.top();
                st.pop();

                res.push_back(node->val);

                while(!st.empty() && node == st.top()->right) { // go to roots
                    node = st.top();
                    st.pop();

                    res.push_back(node->val);
                }
            }
        }
        
        return res;
    }
};