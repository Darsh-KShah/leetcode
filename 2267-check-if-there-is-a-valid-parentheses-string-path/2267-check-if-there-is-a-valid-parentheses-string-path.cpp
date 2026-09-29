class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        if((n + m - 1) % 2) return false;

        if(grid[0][0] == ')' || grid[n - 1][m - 1] == '(') return false;

        vector<vector<vector<bool>>> dp(n, vector<vector<bool>> (m, vector<bool> (n + m, false)));

        dp[0][0][1] = true;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int cnt = 0; cnt < n + m; cnt++) {
                    if(!dp[i][j][cnt]) continue;

                    if(i + 1 < n) {
                        int bal = cnt + (grid[i + 1][j] == '(' ? 1 : -1);

                        if(bal >= 0) dp[i + 1][j][bal] = true;
                    }

                    if(j + 1 < m) {
                        int bal = cnt + (grid[i][j + 1] == '(' ? 1 : -1);

                        if(bal >= 0) dp[i][j + 1][bal] = true;
                    }
                }
            }
        }

        return dp[n - 1][m - 1][0];
    }
};