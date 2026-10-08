class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";

        int depth = 0;

        for(auto &i : s) {
            if(i == '(') {
                depth++;

                if(depth > 1) res.push_back(i);
            } else {
                depth--;

                if(depth > 0) res.push_back(i);
            }
        }

        return res;
    }
};