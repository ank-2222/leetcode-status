class Solution {
    void calSubset(vector<int>&nums,int index,vector<int>sub,vector<vector<int>>&ans){
        if(index>=nums.size()){
            ans.push_back(sub);
            return;
        }

        // divide and conqour
        //exclude
        calSubset(nums,index+1,sub,ans);

        //include 
        sub.push_back(nums[index]);
        calSubset(nums,index+1,sub,ans);
      


    }


public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
      vector<int> sub;
        calSubset(nums, 0, sub, ans);
        return ans;
    }
};