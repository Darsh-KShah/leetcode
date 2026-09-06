class Solution {
public:
    int sol(vector<vector<int>> &dp, string &s, string &t, int x, int y, int n, int m) {
        if(y == m) return 1;

        if(x == n) return 0;

        if(dp[x][y] != -1) return dp[x][y];

        int res = sol(dp, s, t, x + 1, y, n, m);

        if(s[x] == t[y]) res += sol(dp, s, t, x + 1, y + 1, n, m);

        return dp[x][y] = res;
    }

    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();

        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));

        return sol(dp, s, t, 0, 0, n, m);
    }
};