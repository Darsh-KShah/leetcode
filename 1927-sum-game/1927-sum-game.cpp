class Solution {
public:
    bool sumGame(string num) {
        int n = num.size(), lhs = 0, rhs = 0, lc = 0, rc = 0;

        for(int i = 0; i < n / 2; i++) {
            if(num[i] == '?') lc++;
            else lhs += (num[i] - '0');
        }

        for(int i = n / 2; i < n; i++) {
            if(num[i] == '?') rc++;
            else rhs += (num[i] - '0');
        }

        if(lc < rc) {
            rc -= lc;
            lc = 0;
        } else {
            lc -= rc;
            rc = 0;
        }

        if(lc == 0 and rc == 0) return !(lhs == rhs);

        if(lhs > rhs) {
            lhs -= rhs;
            rhs = 0;
        } else {
            rhs -= lhs;
            lhs = 0;
        }

        cout << lhs << " " << rhs << " " << lc << " " << rc;

        if(lhs){
            if(lc) return true;
            else {
                if(rc & 1) return true;
                else return !(9 * (rc / 2) == lhs);
            }
        } else if(rhs) {
            if(lc) {
                if(lc & 1) return true;
                else return !(9 * (lc / 2) == rhs);
            } else return true;
        }

        return true;
    }
};