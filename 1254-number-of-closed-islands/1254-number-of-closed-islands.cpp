class Solution {
public:
    bool dfs(vector<vector<int>> &grid, int i, int j, int n, int m) {
        if(i < 0 || i == n || j < 0 || j == m) return false;

        if(grid[i][j] == 1) return true;

        grid[i][j] = 1;

        bool l = dfs(grid, i, j - 1, n, m);
        bool r = dfs(grid, i, j + 1, n, m);
        bool u = dfs(grid, i - 1, j, n, m);
        bool d = dfs(grid, i + 1, j, n, m);

        return l && r && u && d;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int cnt = 0;

        int n = grid.size(), m = grid[0].size();

        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                if(grid[i][j] == 0) 
                    if(dfs(grid, i, j, n, m)) cnt++;

        return cnt;
    }
};