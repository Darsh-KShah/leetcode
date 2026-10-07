class Solution {
public:
    void tryall(unordered_set<string> &res, string &s, string& cur, int idx, int open) {
        if(open < 0) return;

        if(idx == s.size()) {
            if(open == 0) res.insert(cur);

            return;
        }

        tryall(res, s, cur, idx + 1, open);

        if(s[idx] == ')') {
            if(open) {
                cur.push_back(')');

                tryall(res, s, cur, idx + 1, open - 1);

                cur.pop_back();
            } else return;
        } else if(s[idx] == '(') {
            cur.push_back('(');

            tryall(res, s, cur, idx + 1, open + 1);

            cur.pop_back();
        } else {
            cur.push_back(s[idx]);

            tryall(res, s, cur, idx + 1, open);

            cur.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> res;

        string cur = "";

        tryall(res, s, cur, 0, 0);

        int maxL = 0;

        for(auto &i : res) 
            maxL = max(maxL, (int) i.size());

        vector<string> result;

        for(auto &i : res)
            if(i.size() == maxL) result.push_back(i);

        return result;
    }
};