class Solution {
public:
    const int MOD = 1e9 + 7;

    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (2)));

        dp[0][0][1] = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 && j == 0) continue;

                if(grid[i][j] == 0) {
                    if(i > 0) {
                        if(grid[i - 1][j] == 0) dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
                        else dp[i][j][0] = dp[i - 1][j][0];
                    }

                    if(j > 0) {
                        if(grid[i][j - 1] == 0) dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % MOD;
                        else dp[i][j][1] = dp[i][j - 1][1];
                    }
                } else {
                    if(j > 0) {
                        if(grid[i][j-   1] == 0) dp[i][j][0] = (dp[i][j-1][0] + dp[i][j-1][1]) % MOD;
                        else dp[i][j][0] = dp[i][j-1][1];
                    }

                    if(i > 0) {
                        if(grid[i-1][j] == 0) dp[i][j][1] = (dp[i-1][j][0] + dp[i-1][j][1]) % MOD;
                        else dp[i][j][1] = dp[i-1][j][0];
                    }
                }
            }
        }

        return (dp[n - 1][m - 1][0] + dp[n - 1][m - 1][1]) % MOD;
    }
};