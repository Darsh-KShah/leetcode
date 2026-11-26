class Solution {
public:
    bool canAliceWin(int n) {
        int cur = 10, isALice = 1;

        while(n >= cur) {
            n -= cur--;

            isALice ^= 1;
        }

        return isALice ? false : true;
    }
};