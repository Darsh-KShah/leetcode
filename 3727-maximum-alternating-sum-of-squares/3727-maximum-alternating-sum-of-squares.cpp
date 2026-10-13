class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for(auto &i : nums) 
            i *= i;

        sort(nums.begin(), nums.end());

        long long res = 0;

        for(int i = 0; i < n; i++) {
            if(i < n / 2) res -= nums[i];
            else res += nums[i];
        }

        return res;
    }
};