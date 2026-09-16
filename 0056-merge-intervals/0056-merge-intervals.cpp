class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return intervals;

        sort(intervals.begin(), intervals.end());

        int n = intervals.size(), l = intervals[0][0], r = intervals[0][1];

        vector<vector<int>> res;
        res.reserve(n);

        for(int i = 1; i < n; i++) {
            if(r >= intervals[i][0]) r = max(r, intervals[i][1]);
            else {
                res.push_back({l, r});

                l = intervals[i][0];
                r = intervals[i][1];
            }
        }
        
        res.push_back({l, r});
        
        return res;
    }
};