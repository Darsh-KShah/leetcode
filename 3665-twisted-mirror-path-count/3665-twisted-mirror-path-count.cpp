class Solution {
public:
    const int MOD = 1e9 + 7;

    int cnt(vector<vector<vector<int>>> &dp, vector<vector<int>> &grid, int n, int m, int i, int j, bool wasR) {
        if(i == n || j == m) return 0;

        if(i == n - 1 && j == m - 1) return 1;

        if(dp[i][j][wasR] != -1) return dp[i][j][wasR];

        if(grid[i][j] == 1) return dp[i][j][wasR] = wasR ? cnt(dp, grid, n, m, i + 1, j, 0) % MOD : cnt(dp, grid, n, m, i, j + 1, 1) % MOD;

        return dp[i][j][wasR] = (cnt(dp, grid, n, m, i, j + 1, 1) + cnt(dp, grid, n, m, i + 1, j, 0)) % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (2, -1)));

        return cnt(dp, grid, n, m, 0, 0, 1) % MOD;
    }
};