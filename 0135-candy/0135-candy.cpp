class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), sum = 1, i = 1;

        while(i < n) {
            if(ratings[i] == ratings[i - 1]) {
                sum++;
                i++;
            } else {
                int peak = 1, down = 0;

                while(i < n and ratings[i - 1] < ratings[i]) {
                    peak++;
                    sum += peak;
                    i++;
                }

                while(i < n and ratings[i - 1] > ratings[i]) {
                    down++;
                    sum += down;
                    i++;
                }

                if(down >= peak) sum += down - peak + 1;
            }
        }

        return sum;
    }
};