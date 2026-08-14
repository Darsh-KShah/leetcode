class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;

        string s = to_string(x);
        int n = s.size() / 2;

        for(int i = 0; i < n; i++) { if(s[i] != s[s.length() - i - 1]) return false; }

        return true;
    }
};