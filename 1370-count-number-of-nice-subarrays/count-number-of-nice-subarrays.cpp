class Solution {
public:
    int countSubArray(vector<int>& nums,int goal){
        if(goal<0)return 0;
        int count=0;
        int l=0,r=0,sum=0;
        while(r<nums.size()){
            sum+=nums[r]%2;
            while(l<=r && sum>goal){
                sum-=nums[l]%2;
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
       
        return countSubArray(nums, k) - countSubArray(nums, k - 1);
    }
};