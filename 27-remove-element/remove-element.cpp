class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int sp = len-1;
        int fp = len-1;
        while(fp>=0){
            if(nums[fp]==val){
                nums[fp] = nums[sp];
                sp--;
            }
            fp--;
        }
        return sp-fp;
    }
};