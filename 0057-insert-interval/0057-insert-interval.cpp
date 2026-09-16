class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& ivl, vector<int>& newI) {
        int n = ivl.size();

        vector<vector<int>> res;

        for(int i = 0; i < n; i++) {
            if(ivl[i][1] < newI[0]) res.push_back(ivl[i]);
            else if(newI[1] < ivl[i][0]) {
                res.push_back(newI);

                while(i < n) {
                    res.push_back(ivl[i]);
                    i++;
                }
            } else {
                int l = min(ivl[i][0], newI[0]), r = max(ivl[i][1], newI[1]);

                i++;

                while(i < n && ivl[i][0] <= r) {
                    r = max(r, ivl[i][1]);
                    i++;
                }

                res.push_back({l, r});

                while(i < n) {
                    res.push_back(ivl[i]);                    
                    i++;
                }
            }
        }

        if(res.empty() or res.back()[1] < newI[0]) res.push_back(newI);

        return res;
    }
};