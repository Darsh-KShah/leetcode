class Solution {
public:
    bool isPath(vector<vector<vector<int>>> &dp, vector<vector<char>> &grid, int n, int m, int x, int y, int cnt) {
        if(x == n - 1 && y == m - 1) return cnt == 1 && grid[x][y] == ')';

        if(x == n || y == m) return false;

        if(dp[x][y][cnt] != -1) return dp[x][y][cnt];

        int bal = cnt;

        grid[x][y] == ')' ? bal-- : bal++;

        if(bal < 0) return false;

        bool r = isPath(dp, grid, n, m, x + 1, y, bal);
        bool d = isPath(dp, grid, n, m, x, y + 1, bal);

        return dp[x][y][cnt] = r || d;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        if((n + m - 1) % 2) return false;

        if(grid[0][0] == ')' || grid[n - 1][m - 1] == '(') return false;

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (m + 1, vector<int> (n + m, -1)));

        return isPath(dp, grid, n, m, 0, 0, 0);
    }
};