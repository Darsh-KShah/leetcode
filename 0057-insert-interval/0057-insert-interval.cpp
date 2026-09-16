class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& ivl, vector<int>& newI) {
        int n = ivl.size(), i = 0;

        vector<vector<int>> res;
        res.reserve(n + 1);

        while(i < n && ivl[i][1] < newI[0]) {
            res.push_back(ivl[i]);
            i++;
        }

        while(i < n && ivl[i][0] <= newI[1]) {
            newI[0] = min(newI[0], ivl[i][0]);
            newI[1] = max(newI[1], ivl[i][1]);

            i++;
        }

        res.push_back(newI);

        while(i < n) {
            res.push_back(ivl[i]);

            i++;
        }

        return res;
    }
};