class Solution {
public:
    int minRotations(string s) {
        int n = s.size();

        int res = min(s[0] - '0', 10 - s[0] + '0');

        for(int i = 1; i < n; i++)
            res += min(abs(s[i] - s[i - 1]), 10 - abs(s[i] - s[i - 1]));

        return res;
    }
};