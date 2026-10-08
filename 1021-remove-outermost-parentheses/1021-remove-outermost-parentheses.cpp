class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "", cur = "";

        stack<char> st;

        for(auto &i : s) {
            cur.push_back(i);

            if(i == '(') st.push('(');
            else {
                st.pop();

                if(st.empty()) {                    
                    res += cur.substr(1, cur.size() - 2);

                    cur = "";
                }
            }
        }

        return res;
    }
};