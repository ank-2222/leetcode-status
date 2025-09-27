class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        int low = 0;
        int high = nums1.size();
        int half = (nums1.size() + nums2.size() + 1) / 2;
        int m = nums1.size();
        int n = nums2.size();
        while (low <= high) {
            int i = (low + high) / 2;
            int j = half - i;
            int leftA = (i > 0) ? nums1[i - 1] : INT_MIN;
            int rightA = (i < m) ? nums1[i] : INT_MAX;
            int leftB = (j > 0) ? nums2[j - 1] : INT_MIN;
            int rightB = (j < n) ? nums2[j] : INT_MAX;

            if (leftA <= rightB && leftB <= rightA) {
                if ((m + n) % 2) {
                    return max(leftA, leftB);
                } else {
                    return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
                }

            } else if (leftA > rightB) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }
        return 0.0;
    }
};