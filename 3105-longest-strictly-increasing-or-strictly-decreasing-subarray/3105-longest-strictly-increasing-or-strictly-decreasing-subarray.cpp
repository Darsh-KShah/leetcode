class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size(), longest = 1;

        for(int i = 0; i < n - 1; i++) {
            int cur = 1;

            int j = i + 1;

            if(nums[j - 1] < nums[j]) while(j < n && nums[j - 1] < nums[j]) {
                cur++;
                j++;
            } else if(nums[j - 1] > nums[j]) while(j < n && nums[j - 1] > nums[j]) {
                cur++;
                j++;
            }

            longest = max(longest, cur);
        }

        return longest;
    }
};