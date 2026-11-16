class Solution {
public:
    const int MOD = 1e9 + 7;

    int numOfSubarrays(vector<int>& arr) {
        int res = 0, oddC = 0, evenC = 1, pSum = 0;

        for(auto &i : arr) {
            pSum += i;

            if(pSum & 1) {
                oddC++;
                res += evenC;
            } else {
                evenC++;
                res += oddC;
            }

            res %= MOD;
        }

        return res;
    }
};