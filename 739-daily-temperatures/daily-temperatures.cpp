class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //next greater so decreasing monotonic stack
        stack<int> st;
        vector<int>ans(temperatures.size(),0);
        int n = temperatures.size();
        for(int i =0;i<n;i++){
            while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                ans[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};