class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size(), res = -1;

        for(int i = 0; i < n; i++) {
            int num = nums[i], sum = 0;

            while(num > 0) {
                sum += num % 10;

                num /= 10;
            }

            if(sum == i) {
                res = i;
                break;
            }
        }

        return res;
    }
};