class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int res = 0, lg = 0;

        for(auto &i : lights) 
            lg = max(lg, i);

        for(auto &i : arrivalTime) {
            int arr = i % period;

            if(arr >= lg) res = max(res, period - arr);
        }

        return res;
    }
};