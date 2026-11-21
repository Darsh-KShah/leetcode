class Solution {
public:
    void dfs(vector<int>& parent, string &s, vector<vector<int>> &adj, vector<int> &prev, int idx) {
        int old = prev[s[idx] - 'a'];

        if(old != -1) parent[idx] = old;

        prev[s[idx] - 'a'] = idx;

        for(auto &i : adj[idx]) 
            dfs(parent, s, adj, prev, i);

        prev[s[idx] - 'a'] = old;
    }

    int calcSubT(vector<vector<int>> &updAdj, vector<int> &res, int idx) {
        res[idx] = 1;

        for(auto &i : updAdj[idx]) 
            res[idx] += calcSubT(updAdj, res, i);

        return res[idx];
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        for(int i = 1; i < n; i++) 
            adj[parent[i]].push_back(i);

        vector<int> prev(26, -1);

        dfs(parent, s, adj, prev, 0);

        vector<vector<int>> updAdj(n);

        for(int i = 1; i < n; i++) 
            updAdj[parent[i]].push_back(i);

        vector<int> res(n);

        calcSubT(updAdj, res, 0);

        return res;
    }
};