class Solution {
public:
    int minMoves(vector<int>& nums) {
        int cnt = 0, maxi = *max_element(nums.begin(), nums.end());

        for(auto i : nums) 
            cnt += maxi - i;

        return cnt;
    }
};