class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size(), res = INT_MAX;

        for(int i = l; i <= r; i++) {
            int cur = 0;

            for(int j = 0; j < i; j++) 
                cur += nums[j];
            
            if(cur > 0) res = min(res, cur);

            for(int j = i; j < n; j++) {
                cur += nums[j];
                cur -= nums[j - i];

                if(cur > 0) res = min(res, cur);
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};