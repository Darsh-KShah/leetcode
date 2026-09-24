class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& ivl) {
        sort(ivl.begin(), ivl.end());

        int n = ivl.size();
        
        long long cnt = 0;

        for(int i = 0; i < n - 1; i++) {
            int idx = upper_bound(ivl.begin(), ivl.end(), ivl[i][1], [] (int x, const vector<int> &v) {
                return x < v[0];
            }) - ivl.begin();

            cnt += idx - i - 1;
        }

        return cnt;
    }
};