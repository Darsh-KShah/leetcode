class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int median = nums[nums.size() / 2], res = 0;

        for(auto &i : nums) 
            res += abs(median - i);

        return res;
    }
};