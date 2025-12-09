class Solution {
public:
    inline int distSq(const vector<int>& p) {
        return p[0]*p[0] + p[1]*p[1];
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int,int>> pq; 

        for (int i = 0; i < points.size(); i++) {
            int d = distSq(points[i]);
            pq.push({d, i});

            if (pq.size() > k)
                pq.pop();  
        }

        vector<vector<int>> ans;
        ans.reserve(k);

        while (!pq.empty()) {
            ans.push_back(points[pq.top().second]);  
            pq.pop();
        }

        return ans;
    }
};
