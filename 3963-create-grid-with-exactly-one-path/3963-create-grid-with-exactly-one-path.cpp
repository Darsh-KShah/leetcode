class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> res(m, string(n, '#'));

        res[0] = string(n, '.');

        for(int i = 1; i < m; i++)
            res[i][n - 1] = '.';

        return res;
    }
};