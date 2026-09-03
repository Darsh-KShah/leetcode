class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = nums1[0];

        bool odd = false;

        for(auto &i : nums1) {
            if(i < mini) mini = i;

            if(i & 1) odd = true;
        }

        if(mini & 1) return true;

        return !odd;
    }
};