class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() -1;
        vector<int> ans = {-1, -1};

        while (low <=high) { // left occurance
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                ans[0] = mid;
                high = mid - 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        low = 0;
        high = nums.size() - 1;
        while (low <= high) { // left occurance
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                ans[1] = mid;
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans ;
    }
};