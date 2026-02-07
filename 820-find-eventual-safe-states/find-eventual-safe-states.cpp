class Solution {
private:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis,
             vector<vector<int>>& adjLs, vector<int>& check) {
        vis[node] = 1;
        pathVis[node] = 1;
        for (auto& x : adjLs[node]) {
            if (!vis[x]) {
                if (dfs(x, vis, pathVis, adjLs, check)) 
                return true;
            } else if (pathVis[x]) {

                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> check(V, 0);

        vector<int> safeNode;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {

                dfs(i, vis, pathVis, graph, check);
            }
        }

        for (int i = 0; i < V; i++) {
            if (check[i])
                safeNode.push_back(i);
        }
        return safeNode;
    }
};