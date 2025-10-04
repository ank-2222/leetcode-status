class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len, 1);
        int i = 0;
        int pp = 1;
        while (i < len) {
            ans[i] = pp;
            pp *= nums[i];
            i++;
        }
        int j = len - 1;
        int sp = 1;
        while (j >= 0) {
            ans[j] *= sp;
            sp *= nums[j];
            j--;
        }
        return ans;
    }
};