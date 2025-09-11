class Solution {
public:

    int countSubArray(vector<int>& nums,int goal){
        if(goal<0)return 0;
        int count=0;
        int l=0,r=0,sum=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(l<=r && sum>goal){
                sum-=nums[l];
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countSubArray(nums,goal)-countSubArray(nums,goal-1);
    }
};