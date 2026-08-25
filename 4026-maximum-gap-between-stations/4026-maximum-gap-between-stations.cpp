class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size(), m = station.size(), res = 0;

        if(n == 1) return res;

        vector<int> f(n), b(n);

        int idx = 0;

        for(int i = 0; i < n; i++) {
            while(skill[i] != station[idx]) 
                idx++;

            f[i] = idx++;
        }

        idx = m - 1;

        for(int i = n - 1; i >= 0; i--) {
            while(skill[i] != station[idx])
                idx--;

            b[i] = idx--;
        }

        for(int i = 0; i < n - 1; i++)
            res = max({res, abs(f[i + 1] - b[i]), abs(f[i] - b[i + 1])});

        return res;
    }
};