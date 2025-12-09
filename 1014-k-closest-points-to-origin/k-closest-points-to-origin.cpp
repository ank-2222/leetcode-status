class Solution {
public:
  int getDistance(int x, int y) {
    return x*x + y*y;
}


    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
          priority_queue<pair<int, pair<int, int>>> pq; 

        for (int i = 0; i < points.size(); i++) {
            pq.push({getDistance(points[i][0], points[i][1]),
                    {points[i][0], points[i][1]}});
            if (pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            vector<int> temp;
            pair<int, pair<int, int>> x = pq.top();
            temp.push_back(x.second.first);
            temp.push_back(x.second.second);
            ans.push_back(temp);
            pq.pop();
        }
        return ans;
    }
};