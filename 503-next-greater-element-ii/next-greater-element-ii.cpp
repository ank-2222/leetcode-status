class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack<int> st;
        vector<int> ans(nums.size(),-1);
        int n = nums.size();
        for(int i =0;i<2*n;i++){  //running twice over array to simulate circular and get all next greater in 2 iteration
            while(!st.empty() && nums[st.top()] < nums[i%n]){  //so here am storing index of element in decreasing order, cause later i need index only to update grater element to that index and doing i%n for circular
                ans[st.top()]=nums[i%n];  
                st.pop();
            }
            if(i<n) st.push(i);  // i need to push to stack only for 1 iteration, and gett next greater of element in whatever number of iteration
        }
        return ans;

    }
};