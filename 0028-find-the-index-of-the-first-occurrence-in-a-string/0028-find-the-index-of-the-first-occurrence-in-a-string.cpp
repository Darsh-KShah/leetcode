class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.length() < needle.length()) return -1;
        else if(haystack.length() == needle.length()) return haystack == needle ? 0 : -1;
        else 
            for(int i = 0; i <= haystack.length() - needle.length(); i++)
                if(needle == haystack.substr(i, needle.length())) return i;

        return -1;
    }
};