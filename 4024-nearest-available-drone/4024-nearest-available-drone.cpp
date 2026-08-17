class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n = drones.size();

        map<int, int> mp;

        for(int i = 0; i < n; i++) {
            int md = abs(target[0] - drones[i][0]) + abs(target[1] - drones[i][1]);

            if(md <= drones[i][2]) {
                if(mp.count(md)) {

                } else mp[md] = i;
            }
        }

        return mp.size() ? mp.begin()->second : -1;
    }
};