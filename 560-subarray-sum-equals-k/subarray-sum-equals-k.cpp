class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

       map<int, int> mp;
        mp[0] = 1;
        int count = 0, i = 0, sum = 0;
        while (i < nums.size()) {
            sum += nums[i];
            count += mp[sum - k];
            mp[sum]++;
            i++;
        }
        return count;
    }
};