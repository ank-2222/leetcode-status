class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int monday = 1; 
        int day = 0; 
        int cur = monday; 

        for (int i = 0; i < n; ++i) {
            ans += cur;
            ++day;
            if (day == 7) {
                day = 0;
                ++monday;
                cur = monday;
            } else {
                ++cur;
            }
        }
        return ans;
    }
};
