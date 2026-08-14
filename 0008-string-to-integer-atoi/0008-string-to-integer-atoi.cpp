class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        if(n == 0) return 0;
        int i = 0;
        bool neg = false;
        string maxi = to_string(INT_MAX), mini = "2147483648", res = "";

        while(i < n && s[i] == ' ') i++;

        if(i < n && (s[i] == '-' || s[i] == '+')) {
            if(s[i] == '-') neg = true;
            i++;
        }

        while(i < n) {
            if('0' <= s[i] && s[i] <= '9') {
                if(s[i] == '0' && res == "0") {
                    i++;
                    continue;
                };
                res.push_back(s[i]);

                if(neg) { if(res.length() > mini.length() || (res.length() == mini.length()  && res >= mini)) return INT_MIN; }
                else { if(res.length() > maxi.length() || (res.length() == mini.length()  && res >= maxi)) return INT_MAX; }
            } else break;
            i++;
        }

        if(res.length() == 0) return 0;

        return neg ? -1*stoi(res) : stoi(res);
    }
};