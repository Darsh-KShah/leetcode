class Solution {
public:
    bool sumGame(string num) {
        int n = num.size(), lhs = 0, rhs = 0, lc = 0, rc = 0;

        for(int i = 0; i < n / 2; i++) {
            if(num[i] == '?') lc++;
            else lhs += num[i] - '0';

            if(num[n - 1 - i] == '?') rc++;
            else rhs += num[n - 1 - i] - '0';
        }

        if(lc < rc) {
            rc -= lc;
            lc = 0;
        } else {
            lc -= rc;
            rc = 0;
        }

        if(lc == 0 and rc == 0) return lhs != rhs;

        if(lhs > rhs) {
            lhs -= rhs;
            // rhs = 0;
        } else {
            rhs -= lhs;
            lhs = 0;
        }

        if(lhs){
            if(lc) return true;
            
            if(rc & 1) return true;
            
            return lhs != 9 * (rc / 2);
        } else if(rhs) {
            if(lc) {
                if(lc & 1) return true;
                
                return rhs != 9 * (lc / 2);
            } 
            
            return true;
        }

        return true;
    }
};