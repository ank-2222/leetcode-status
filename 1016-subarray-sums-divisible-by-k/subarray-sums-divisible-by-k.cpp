class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0, presum = 0;
        map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            presum += nums[i]; //find presum

            int rem = presum % k; //presum[i]%k == presum[j]%k , where i<j at this condition , subarray between j adn i is divisible by k
            rem = (rem + k) % k; //normalise before entry to map for -ve sum 

            count += mp[rem];
            mp[rem]++;
        }
        return count;
    }
};