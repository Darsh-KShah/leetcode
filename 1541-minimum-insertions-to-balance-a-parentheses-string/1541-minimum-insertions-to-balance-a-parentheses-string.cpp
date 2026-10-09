class Solution {
public:
    int minInsertions(string s) {
        int req = 0, brac = 0;

        for(auto &i : s) {
            if(i == '(') {
                brac += 2;

                if(brac & 1) {
                    req++;

                    brac--;
                }
            } else {
                brac--;

                if(brac < 0) {
                    req++;

                    brac = 1;
                }
            }
        }

        return req + brac;
    }
};