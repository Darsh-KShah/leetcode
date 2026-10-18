class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int x = 0, y = 0, i = 0, j = 0;

        while(true) {
            if(grid[i][j] == '#') break;
            
            x = i;
            y = j;            

            char cur = grid[i][j];

            grid[i][j] = '#';

            if(cur == 'U') {
                if(i == 0) break;
                else i--;
            } else if(cur == 'D') {
                if(i == n - 1) break;
                else i++;
            } else if(cur == 'L') {
                if(j == 0) break;
                else j--;
            } else {
                if(j == m - 1) break;
                else j++;
            }
        }

        return {x, y};
    }
};