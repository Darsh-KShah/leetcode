class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        char maxi = s[0], mini = s[0];

        bool isSorted = true;

        for(int i = 1; i < n; i++) {
            if(s[i] < s[i - 1]) isSorted = false;

            maxi = max(maxi, s[i]);
            mini = min(mini, s[i]);
        }

        if(isSorted) return 0;

        if(n == 2) return -1;

        if(s[0] == mini || s[n - 1] == maxi) return 1;

        for(int i = 1; i < n - 1; i++) 
            if(s[i] == mini || s[i] == maxi) return 2;

        return 3;
    }
};