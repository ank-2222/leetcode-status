class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                nums[i] = -1;
            }
        }
        map<int, int> mp;
        int maxLen = 0;
        int presum = 0;
        mp[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            presum += nums[i];
            if (mp.find(presum) != mp.end()) // we saw this prefix sum before
            {
                maxLen = max(maxLen, i-mp[presum]);
            }else{

            mp[presum] = i;
            }
        }
        return maxLen;
    }
};