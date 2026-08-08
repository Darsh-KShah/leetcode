class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        unordered_map<char, int> um;

        int maxi = 0, l = 0;

        for(int i = 0; i < n; i++) {
            if(um.find(s[i]) != um.end()) {
                while(um[s[i]] != 0) {
                    um[s[l]]--;
                    if(um[s[l]] == 0) um.erase(s[l]);

                    l++;
                }                
            }
            um[s[i]]++;
            maxi = max(maxi, i - l + 1);
        }

        return maxi;
    }
};