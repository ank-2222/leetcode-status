class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        queue<int> q;
        vector<vector<int>> rev(V);

        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++) {
            for (auto x : graph[i]) {
                rev[x].push_back(i);
                indegree[i]++;
            }
        }
        vector<int> ans;

        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                ans.push_back(i);
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto& it : rev[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};