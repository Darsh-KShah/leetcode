class Solution {
public:
    int digits(int n) {
        int cnt = 1;

        while(n > 0) {
            cnt *= 10;

            n /= 10;
        }

        return cnt;
    }

    int minMergedInteger(vector<int>& nums) {
        int n = nums.size(), res = INT_MAX;

        for(int i = 0; i < n; i += 2) 
            res = min(res, nums[i] * digits(nums[i + 1]) + nums[i + 1]);

        return res;
    }
};