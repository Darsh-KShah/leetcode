class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for(auto &i : s) {
            if(i =='(') st.push(0);
            else {
                int prev1 = st.top();
                st.pop();

                int prev2 = st.top();

                st.pop();

                st.push(prev2 + max(2 * prev1, 1));
            }
        }

        return st.top();
    }
};