class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9 * num) return "";

        string res(sum / 9, '9');

        if(sum % 9) res.push_back(sum % 9 + '0');

        res.append(num - res.size(), '0');

        return res;
    }
};