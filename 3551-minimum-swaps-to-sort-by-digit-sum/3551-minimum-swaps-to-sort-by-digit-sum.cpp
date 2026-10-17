class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for(auto &i : nums) {
            int num = i, sum = 0;

            while(num > 0) {
                sum += (num % 10);

                num /= 10;
            }

            mp[i] = sum;
        }

        vector<int> idx(n);

        for(int i = 0; i < n; i++)
            idx[i] = i;

        sort(idx.begin(), idx.end(), [&mp, &nums] (int A, int B) {
            if(mp[nums[A]] == mp[nums[B]]) return nums[A] < nums[B];

            return mp[nums[A]] < mp[nums[B]];
        });

        int swaps = 0;

        for(int i = 0; i < n; i++) {
            while(idx[i] != i) {
                swap(idx[i], idx[idx[i]]);

                swaps++;
            }
        }

        return swaps;
    }
};