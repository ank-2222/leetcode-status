class Solution {
private:
    bool isBip(int start, vector<vector<int>>& adjLs, vector<int>& color) {
        queue<int> q;
        color[start] = 0;

        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto& x : adjLs[node]) {
                if (color[x] == -1) {
                    q.push(x);
                    color[x] = !color[node];
                } else if (color[x] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
      vector<vector<int>> adjLs(n);


        for (int i = 0; i < n; i++) {
            for (auto v : graph[i]) {
                adjLs[i].push_back(v);
            }
        }
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (isBip(i, adjLs, color) == false)
                    return false;
            }
        }
        return true;
    }
};