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
    void sol(unordered_map<int, vector<pair<int, int>>> &mp, TreeNode* node, int row, int col, int &mini) {
        if(node == NULL) return;

        mini = min(mini, col);

        mp[col].push_back({row, node->val});

        sol(mp, node->left, row + 1, col - 1, mini);
        sol(mp, node->right, row + 1, col + 1, mini);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;        

        unordered_map<int, vector<pair<int, int>>> mp;

        int mini = 0;

        sol(mp, root, 0, 0, mini);

        while(true) {
            if(!mp.count(mini)) break;

            int n = mp[mini].size();

            sort(mp[mini].begin(), mp[mini].end());

            vector<int> temp(n);

            for(int i = 0; i < n; i++)
                temp[i] = mp[mini][i].second;

            res.push_back(temp);

            mini++;
        }

        return res;
    }
};