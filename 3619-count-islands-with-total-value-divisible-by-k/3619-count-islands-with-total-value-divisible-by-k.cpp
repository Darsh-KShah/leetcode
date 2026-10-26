class Solution {
public:
    long dfs(vector<vector<int>> &grid, int i, int j, int n, int m) {
        if(i < 0 || j < 0 || i == n || j == m) return 0;

        if(grid[i][j] == 0) return 0;

        long res = grid[i][j];

        grid[i][j] = 0;

        long l = dfs(grid, i, j - 1, n, m);
        long r = dfs(grid, i, j + 1, n, m);
        long u = dfs(grid, i - 1, j, n, m);
        long d = dfs(grid, i + 1, j, n, m);

        return res + l + r + u + d;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();

        int cnt = 0;

        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                if(grid[i][j] != 0) 
                    if(dfs(grid, i, j, n, m) % k == 0) cnt++;

        return cnt;
    }
};