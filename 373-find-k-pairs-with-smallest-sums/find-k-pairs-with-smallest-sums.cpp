class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        vector<vector<int>> ans;
        if (nums1.empty() || nums2.empty() || k == 0)
            return ans;

        using T = tuple<long long, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        int n1 = nums1.size();
        int n2 = nums2.size();

        int limit = min(n1, k);

        for (int i = 0; i < limit; i++) {
            pq.emplace((long long)nums1[i] + nums2[0], i, 0);
        }

        while (k-- > 0 && !pq.empty()) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            ans.push_back({nums1[i], nums2[j]});
            if (j + 1 < n2) {
                pq.emplace((long long)nums1[i] + nums2[j + 1], i, j + 1);
            }
        }
        return ans;
    }
};