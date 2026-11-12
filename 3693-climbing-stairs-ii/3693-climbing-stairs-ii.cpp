class Solution {
public:
    int minC(vector<int> &dp, vector<int> &costs, int target, int cur) {
        if(cur == target) return 0;

        if(dp[cur] != -1) return dp[cur];

        int res = minC(dp, costs, target, cur + 1) + 1 + costs[cur + 1 - 1];

        if(cur + 3 <= target) res = min(res, minC(dp, costs, target, cur + 3) + 9 + costs[cur + 3 - 1]);
        if(cur + 2 <= target) res = min(res, minC(dp, costs, target, cur + 2) + 4 + costs[cur + 2 - 1]);

        return dp[cur] = res;
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, -1);

        return minC(dp, costs, n, 0);
    }
};