class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(),  n2 = nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);        
        int low = 0, high = n1;
        int total = (n1 + n2 + 1) / 2;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int l1 = (mid > 0) ? nums1[mid - 1] : INT_MIN;
            int l2 = (total - mid > 0) ? nums2[total - mid - 1] : INT_MIN;
            int r1 = (mid < n1) ? nums1[mid] : INT_MAX;
            int r2 = (total - mid < n2) ? nums2[total - mid] : INT_MAX;
            if(l1 <= r2 && l2 <= r1) {
                if((n1 + n2) % 2 != 0) return max(l1, l2);
                return double(max(l1, l2) + min(r1, r2)) / 2.0;
            } else if(l1 > r2) high = mid - 1;
            else low = mid + 1;
        }
        return 0;
    }
};