class Solution {
public:
    void tryall(unordered_set<string> &res, string &s, string& cur, int idx, int open, int targetSize) {
        if(cur.size() + s.size() - idx < targetSize) return;

        if(idx == s.size()) {
            if(open == 0 && cur.size() == targetSize) res.insert(cur);

            return;
        }

// not take
        tryall(res, s, cur, idx + 1, open, targetSize);

// take
        if(s[idx] == ')') {
            if(open) {
                cur.push_back(')');

                tryall(res, s, cur, idx + 1, open - 1, targetSize);

                cur.pop_back();
            } else return;
        } else if(s[idx] == '(') {
            cur.push_back('(');

            tryall(res, s, cur, idx + 1, open + 1, targetSize);

            cur.pop_back();
        } else {
            cur.push_back(s[idx]);

            tryall(res, s, cur, idx + 1, open, targetSize);

            cur.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> res;

        string cur = "";

        int open = 0, errors = 0;

        for(auto &i : s) {
            if(i == '(') open++;
            else if(i == ')') {
                if(open > 0) open--;
                else errors++;
            }
        }

        int targetSize = s.size() - open - errors;

        tryall(res, s, cur, 0, 0, targetSize);

        vector<string> result;

        for(auto &i : res)
            result.push_back(i);

        return result;
    }
};