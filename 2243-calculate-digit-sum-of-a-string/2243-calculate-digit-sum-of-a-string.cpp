class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k) {
            string temp = "";

            int n = s.size(), cur = 0;

            for(int i = 0; i < n; i++) {
                cur += s[i] - '0';

                if((i + 1) % k == 0) {
                    temp += to_string(cur);

                    cur = 0;
                }
            }

            if(n % k) temp += to_string(cur); 

            s = temp;
        }

        return s;
    }
};