class Solution {
public:
    void Rec(vector<string> &res, string &digits, vector<string> &mp, string &cur, int idx) {
        if(idx == digits.size()) {
            res.push_back(cur);
            return;
        }

        string &letters = mp[digits[idx] - '0' - 2];

        for(char i : letters) {
            cur.push_back(i);
            Rec(res, digits, mp, cur, idx + 1);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string cur;

        vector<string> mp = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

        Rec(res, digits, mp, cur, 0);

        return res;
    }
};