class Solution {
    bool isIncreasing(vector<int>& nums, int k, int i) {
        while (--k) {
            if (nums[i] >= nums[i + 1])
                return false;
                i++;
        }
        return true;
    }

public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
     int n = nums.size();

        for (int i = 0; i <= n - (2 * k); i++) {
            if (isIncreasing(nums, k, i) && isIncreasing(nums, k, i + k))
                return true;
        }
        return false;
    }
};