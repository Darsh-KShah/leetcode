class Solution {
public:
    int findNthDigit(int n) {
        int grpStart = 1, grpDigits = 1;

        long long grpCnt = 9;

        while(n > grpCnt * grpDigits) {
            n -= grpCnt * grpDigits;

            grpDigits++;

            grpCnt *= 10;

            grpStart *= 10;
        }

        long long num = grpStart + (n - 1) / grpDigits;

        string s = to_string(num);

        return s[(n - 1) % grpDigits] - '0';
    }
};