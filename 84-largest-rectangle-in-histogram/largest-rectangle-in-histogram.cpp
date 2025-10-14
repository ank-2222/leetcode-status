class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea =0;
        stack<int>st;
        int n = heights.size();
        for(int i =0;i<=n;i++){
            while(!st.empty() &&(i==n || heights[i]<heights[st.top()]) ){ //i==n for last element to consider
                int tp = st.top();
                st.pop();
                int width = st.empty()?i:i-st.top()-1;
                maxArea = max(maxArea,width*heights[tp]);

            }
             st.push(i);
        }
        return maxArea;
    }
};