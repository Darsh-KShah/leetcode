class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> l = {nums[0]}, r = {nums[1]};

        int n = nums.size();

        for(int i = 2; i < n; i++) {
            if(l.back() > r.back()) l.push_back(nums[i]);
            else r.push_back(nums[i]);
        }

        l.insert(l.end(), r.begin(), r.end());

        return l;
    }
};