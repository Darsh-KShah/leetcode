class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(k == nums.size()) return *max_element(nums.begin(), nums.end());

        vector<int> v(51);

        for(auto &i : nums)
            v[i]++;

        if(k == 1) {
            for(int i = 50; i >= 0; i--) {
                if(v[i] == 1) return i;
            }
            
            return -1;
        }

        int res = -1;

        if(v[nums[0]] == 1) res = max(res, nums[0]);

        if(v[nums.back()] == 1) res = max(res, nums.back());

        return res;
    }
};