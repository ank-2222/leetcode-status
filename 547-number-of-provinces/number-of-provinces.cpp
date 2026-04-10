class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[node] = true;
        
        for(int neighbor : adj[node]) {
            if(!vis[neighbor]) {
                dfs(neighbor, adj, vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        // Build adjacency list
        vector<vector<int>> adj(n);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }
        
        // Count connected components using DFS
        vector<bool> vis(n, false);
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis);
                count++;
            }
        }
        
        return count;
    }
};