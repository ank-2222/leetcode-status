class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        int presum = 0;

        map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            presum += nums[i];

            int rem = presum % k ;
            if (mp.find(rem) != mp.end()) {
                if (i - mp[rem] >= 2) {
                    return true;
                }
            } else {
                mp[rem] = i;
            }
        }
        return false;
    }
};