class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int a = 0, b = 0, c = 0;

        for(int i = 1; i <= n; i++) {
            int cur = costs[i - 1] + min({a + 9, b + 4, c + 1});

            a = b;
            b = c;
            c = cur;
        }

        return c;
    }
};