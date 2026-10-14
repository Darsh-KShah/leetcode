class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9 * num) return "";

        string res(sum / 9, '9');

        int rem = sum % 9;

        if(rem) res.push_back(rem + '0');

        res.append(num - res.size(), '0');

        return res;
    }
};