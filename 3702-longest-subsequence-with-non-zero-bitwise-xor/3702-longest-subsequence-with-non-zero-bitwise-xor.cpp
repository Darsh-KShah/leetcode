class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size(), xr = 0, cnt0 = 0;

        for(auto &i : nums) {
            xr ^= i;

            if(!i) cnt0++;
        }

        if(xr) return n;

        return cnt0 != n ? n - 1 : 0;
    }
};