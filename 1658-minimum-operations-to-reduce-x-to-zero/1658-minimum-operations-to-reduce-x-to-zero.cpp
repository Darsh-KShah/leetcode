class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int k = accumulate(nums.begin(), nums.end(), 0) - x;

        if(k < 0) return -1;
        if(k == 0) return n;

        int j = 0, sum = 0, maxi = -1;

        for(int i = 0; i < n; i++) {
            sum += nums[i];

            while(sum > k) 
                sum -= nums[j++];

            if(sum == k) maxi = max(maxi, i - j + 1);
        }

        return maxi == -1 ? maxi : n - maxi;
    }
};