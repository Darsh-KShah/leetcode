class Solution {
public:
    void generate(string &s, int open, int close, vector<string> &res) {
        if(open == 0 && close == 0) res.push_back(s);

        if(open > 0) {
            s.push_back('(');

            generate(s, open - 1, close, res);

            s.pop_back();
        }

        if(close > 0 && open < close) {
            s.push_back(')');

            generate(s, open, close - 1, res);
            
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;

        string s = "";

        generate(s, n, n, res);

        return res;
    }
};