class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0, prev=0;
        for(auto& row: bank){
            int dev=count(row.begin(), row.end(), '1');
            if (dev>0){
                ans+=dev*prev;
                prev=dev;
            }
        }
        return ans;
    }
};