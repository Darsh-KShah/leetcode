class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int cntL = 0, cntT = 0;

        for(auto &i : nums) {
            if(i < target) cntL++;
            else if(i == target) cntT++;
        }

        vector<int> res;

        for(int i = cntL; i < cntL + cntT; i++) 
            res. push_back(i);

        return res;
    }
};