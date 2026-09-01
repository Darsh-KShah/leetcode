class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = 1, n = nums.size();

        for(int i = 1; i < n; i++) {
            if(nums[cur - 1] < nums[i]) {
                nums[cur] = nums[i];
                cur++;
            }
        }

        return cur;
    }
};