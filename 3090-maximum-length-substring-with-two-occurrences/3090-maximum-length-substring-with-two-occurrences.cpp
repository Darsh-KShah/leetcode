class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26);

        int n = s.size(), l = -1, res = 0;;

        for(int r = 0; r < n; r++) {
            int cur = s[r] - 'a';

            freq[cur]++;

            while(freq[cur] > 2)
                freq[s[++l] - 'a']--;

            res = max(res, r - l);
        }

        return res;
    }
};