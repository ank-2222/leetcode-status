class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int high=nums.size()-1;
        int low = 0;
        while(high-low>1){
            int mid = (high+low)/2;
            if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid;
            }
        }
  if(nums[low] == target) return low;
else if(nums[high] == target) return high;
else if(nums[low] > target) return low;
else if(nums[high] > target) return high;
else return high + 1;

    }
};