class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        
        long long res = 0;

        for(int i = 0; i < n - 1; i++)
            for(int j = i + 1; j < n; j++) {
                long long hcf = gcd(nums[i], nums[j]);

                res = max(res, (1LL * nums[i] * nums[j]) / (hcf * hcf));
            }

        return res;   
    }
};