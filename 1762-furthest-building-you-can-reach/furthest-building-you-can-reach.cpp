class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {

        priority_queue<int, vector<int>,greater<int>> diffs;
        int brickCnt =bricks;
       for(int i =0;i<heights.size()-1;i++){
            int diff = heights[i+1]-heights[i];
            if(diff>0) diffs.push(diff);

            if(diffs.size()>ladders){
                int top = diffs.top();
                diffs.pop();

                brickCnt-=top;

                if(brickCnt<0)return i;

            }
       } 
       return heights.size()-1;
    }
};