class Solution {
public:
    int trap(vector<int>& height) {

    
        int count = 0;
        int l=0,r=height.size()-1;
        int leftmax=0;
        int rightmax=0;
        while (l < r) {
          if(height[l]<height[r]){
            leftmax=max(leftmax,height[l]);
            count+=leftmax-height[l];
            l++;
          }else{
            rightmax=max(rightmax,height[r]);
            count+=rightmax-height[r];
            r--;
          }
        }
        return count;
    }
};