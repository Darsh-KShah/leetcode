class Solution {
public:
    string reverseParentheses(string s) {
        string res = "";

        stack<int> st;

        for(auto &i : s) {
            if(i == '(') st.push(res.size());
            else if(i== ')') {
                int idx = st.top();

                st.pop();

                reverse(res.begin() + idx, res.end());
            } else res.push_back(i);
        }

        return res;
    }
};