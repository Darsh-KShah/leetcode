class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), ct = 0;
        vector<int> v(n, 1);
        for(int i=1; i<n; i++) if(ratings[i] > ratings[i-1]) v[i] = v[i-1] + 1;
        for(int i=n-1; i>0; i--) {
            if(ratings[i-1] > ratings[i] && v[i-1] <= v[i]) v[i-1] = v[i] + 1;
            ct += v[i];
        }
        return ct + v[0];
    }
};