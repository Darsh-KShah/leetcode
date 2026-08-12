class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        int l = -1, r = 0, res = 0;

        while(r < n) {
            mp[nums[r]]++;

            while(mp[nums[r]] > k)
                mp[nums[++l]]--;

            res = max(res, r - l);

            r++;
        }

        return res;
    }
};