class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
         vector<vector<int>> adj(V);
       vector<int> indegree(V,0);
       for(auto &x:prerequisites){
           int u =x[0];
           int v = x[1];
           adj[u].push_back(v);
           indegree[v]++;
           
       }
       
       
    queue<int> q;
    vector<int> ans;
    for(int i =0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
            ans.push_back(i);
        }
    }
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(auto &it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0) {
            q.push(it);
            ans.push_back(it);
        }
        }
        
    }
    return ans.size()==V;
    }
};