class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rS) {
        int res = 0;

        unordered_map<int, unordered_set<int>> mp;

        for(auto &i : rS)
            mp[i[0]].insert(i[1]);

        res += 2 * (n - mp.size());

        for(auto &i : mp) {
            bool l = true, r = true, c = true;

            if(i.second.count(4) or i.second.count(5)) {
                l = false;
                c = false;
            }

            if(i.second.count(6) or i.second.count(7)) {
                c = false;
                r = false;
            }

            if(i.second.count(2) or i.second.count(3)) l = false;

            if(i.second.count(8) or i.second.count(9)) r = false;

            if(!c) {
                if(l or r) res++;
            } else {
                if(l and r) res += 2;
                else res++;
            }
        }

        return res;
    }
};