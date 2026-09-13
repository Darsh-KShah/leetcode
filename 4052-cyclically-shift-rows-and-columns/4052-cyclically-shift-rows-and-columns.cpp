class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        for(int i = 0; i < n; i++) {
            int k = rowShift[i];

            if(k) {
                reverse(grid[i].begin(), grid[i].begin() + k);
                reverse(grid[i].begin() + k, grid[i].end());

                reverse(grid[i].begin(), grid[i].end());
            }
        }

        vector<int> temp = {};

        for(int j = 0; j < n; j++) {
            int k = colShift[j];

            if(k) {
                for(int i = 0; i < k; i++) 
                    temp.push_back(grid[i][j]);
                
                for(int i = k; i < n; i++)
                    grid[i - k][j] = grid[i][j];

                for(int i = n - k; i < n; i++)
                    grid[i][j] = temp[i - n + k];

                temp.clear();
            }
        }

        return grid;
    }
};