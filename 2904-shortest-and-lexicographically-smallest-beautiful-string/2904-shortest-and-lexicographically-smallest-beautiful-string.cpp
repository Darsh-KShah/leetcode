class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        set<string> st;

        int l = 0, r = 0, cnt = 0, mini = INT_MAX;

        while(r < n) {
            if(s[r] == '1') cnt++;

            while(cnt > k) {
                if(s[l] == '1') cnt--;

                l++;
            }

            if(cnt == k) {
                while(s[l] == '0') 
                    l++;

                int cur = r - l + 1;

                if(cur < mini) {
                    st.clear();

                    mini = cur;
                }
                
                if(cur == mini) st.insert(s.substr(l, cur));
            }
            
            r++;
        }

        return st.empty() ? "" : *st.begin();
    }
};