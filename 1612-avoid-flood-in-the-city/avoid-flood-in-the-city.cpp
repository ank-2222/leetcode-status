class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {

        unordered_map<int, int> full;
        set<int> dry_day;
        vector<int> ans(rains.size(), 1);

        for (int i = 0; i < rains.size(); i++) {
            if (rains[i] > 0) {
                if (full.find(rains[i]) == full.end()) {

                    full[rains[i]] = i;
                    ans[i] = -1;

                } else {
                    int prevDay = full[rains[i]];
                    auto it = dry_day.upper_bound(prevDay);
                    if (it == dry_day.end())
                        return {};
                    int dryDay = *it;

                    ans[dryDay] = rains[i];
                    dry_day.erase(it);
                    full[rains[i]] = i;
                    ans[i] = -1;
                }
            } else {
                dry_day.insert(i);
            }
        }
        return ans;
    }
};