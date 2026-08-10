class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN || x == 0) return 0;
        
        bool sign = false;

        if(x < 0) {
            sign = true;
            x *= -1;
        }

        long res = 0;

        while(x) {
            res = res*10 + (x % 10);

            if(res > INT_MAX) return 0;
            
            x /= 10;
        }

        return sign ? -res : res;
    }
};