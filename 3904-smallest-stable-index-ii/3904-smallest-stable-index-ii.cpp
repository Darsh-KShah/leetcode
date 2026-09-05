class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size(), maxi = -1;

        vector<int> back(n);
        back[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 0; i--)
            back[i] = min(back[i + 1], nums[i]);

        for(int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);

            if(maxi - back[i] <= k) return i;
        }

        return -1;
    }
};