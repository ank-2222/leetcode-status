class Solution {
private:
    bool isBip(int start, vector<vector<int>>& adjLs, vector<int>& color) {
      
   

        for(auto &x: adjLs[start]){
            if(color[x]==-1){
                color[x]=!color[start];
               if (!isBip(x, adjLs, color)) return false;
            }else if(color[x]==color[start]){
                return false;
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
                     color[i] = 0;
                if (isBip(i, adjLs, color) == false)
                    return false;
            }
        }
        return true;
    }
};