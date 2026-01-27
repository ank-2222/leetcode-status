class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));

        queue<pair<int,int>> q;

        for(int i =0;i<m;i++){

            if(grid[i][0]==1 && vis[i][0]==0){
                vis[i][0]=1;
                q.push({i,0});
            }

            if(grid[i][n-1]==1 && vis[i][n-1]==0){
                   vis[i][n-1]=1;
                q.push({i,n-1});
            }
        }

        for(int i =0;i<n;i++){
            if(grid[0][i]==1 && vis[0][i]==0){
                vis[0][i]=1;
                q.push({0,i});
            }

            if(grid[m-1][i]==1 && vis[m-1][i]==0){
                   vis[m-1][i]=1;
                q.push({m-1,i});
            }
        }

        vector<int> delRow ={0,0,1,-1};
        vector<int> delCol = {-1,1,0,0};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int d=0;d<4;d++){
                int nRow = row + delRow[d];
                int nCol = col + delCol[d];

                if(nRow>=0 && nRow<grid.size() && nCol >=0 && nCol<grid[0].size() && grid[nRow][nCol]==1 && vis[nRow][nCol]==0){
                    vis[nRow][nCol]=1;
                    q.push({nRow,nCol});
                }
            }
        }

        int count=0;
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    count++;
                }
            }
        }
        return count;
    }
};