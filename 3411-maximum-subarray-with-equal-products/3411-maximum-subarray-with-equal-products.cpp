class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size(), maxLen = 0;

        for(int i = 0; i < n - 1; i++) {
            long long curLcm = nums[i], curGcd = nums[i], curProd = nums[i];

            for(int j = i + 1; j < n; j++) {
                curLcm = lcm(curLcm, nums[j]);
                curGcd = gcd(curGcd, nums[j]);
                curProd *= nums[j];

                if(curProd > curLcm * curGcd) break;

                if(curLcm * curGcd == curProd) maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }
};