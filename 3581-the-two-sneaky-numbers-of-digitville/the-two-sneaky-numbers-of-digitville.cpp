class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n, false);
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (seen[nums[i]]) {
                res.push_back(nums[i]);
            } else {
                seen[nums[i]] = true;
            }
        }
        if (res.size() == 2 && res[0] > res[1]) {
            swap(res[0], res[1]);
        }
        return res;
    }
};