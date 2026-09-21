class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(), nums.end());
        
        int n = nums.size(), pivot = -1;

        for(int i = n - 1; i > 0; i--) {
            if(nums[i] > nums[i - 1]) {
                pivot = i - 1;
                break;
            }
        }

        if(pivot == -1) reverse(nums.begin(), nums.end());
        else {
            int swapId = - 1;

            for(int i = pivot + 1; i < n; i++) { if(nums[i] > nums[pivot]) swapId = i; }

            swap(nums[swapId], nums[pivot]);

            reverse(nums.begin() + pivot + 1, nums.end());
        }
    }
};