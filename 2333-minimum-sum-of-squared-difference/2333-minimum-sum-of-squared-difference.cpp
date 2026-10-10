class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size(), maxi = 0;

        long long k = k1 + k2;

        vector<int> diff(n);

        for(int i = 0; i < n; i++)
            maxi = max(maxi, diff[i] = abs(nums1[i] - nums2[i]));

        vector<int> freq(maxi + 1);

        for(auto &i : diff) 
            freq[i]++;

        for(int i = maxi; i > 0 && k > 0; i--) {
            int redu = min((long long) freq[i], k);

            freq[i] -= redu;

            freq[i - 1] += redu;

            k -= redu;
        }

        long long res = 0;

        for(int i = 1; i <= maxi; i++)
            res += 1LL * i * i * freq[i];

        return res;
    }
};