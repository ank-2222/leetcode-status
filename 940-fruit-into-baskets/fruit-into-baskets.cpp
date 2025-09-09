class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxlen = 0;
        int n = fruits.size();
        int l = 0;
        map<int, int> mp;
        int r = 0;
        while (r < n) {
            mp[fruits[r]]++;
            if (mp.size() <= 2) {
                maxlen = max(maxlen, r - l + 1);

            } else {
                   mp[fruits[l]]--;
                    if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                    l++;
          

            }
              r++;
        }
        return maxlen;
    }
};