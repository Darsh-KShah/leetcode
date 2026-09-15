class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> v(n, 1);

        for(int i = 1; i < n; i++)
            if(ratings[i - 1] < ratings[i]) v[i] = v[i - 1] + 1;

        int cnt = v[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1]) v[i] = max(v[i + 1] + 1, v[i]);

            cnt += v[i];
        }

        return cnt;
    }
};