class Solution {
public:
    int minAddToMakeValid(string s) {
        int cur = 0, req = 0;

        for(auto &i : s) {
            if(i == '(') cur++;
            else cur > 0 ? cur-- : req++;
        }

        return req + cur;
    }
};