class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int s1 = 1e9 + 3, s2 = 1e9 + 3, s3 = 1e9 + 3, l1 = 0, l2 = 0, l3 = 0;

        for(auto &i : nums) {
            if(i < s1) {
                s3 = s2;
                s2 = s1;
                s1 = i;
            } else if(i < s2) {
                s3 = s2;
                s2 = i;
            } else if(i < s3) s3 = i;

            if(i > l1) {
                l3 = l2;
                l2 = l1;
                l1 = i;
            } else if(i > l2) {
                l3 = l2;
                l2 = i;
            } else if(i > l3) l3 = i;
        }

        return min({l1 - s3, l3 - s1, l2 - s2});
    }
};