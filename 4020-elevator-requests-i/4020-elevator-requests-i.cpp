class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int m = requests.size();

        int res = 0, cur = 0;

        for(int i = 0; i < m; i++) {
            res += abs(cur - requests[i]);

            cur = requests[i];
        }

        return res;
    }
};