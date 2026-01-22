class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        vector<vector<int>> ans(m,vector<int>(n,0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j]==0) {
                    vis[i][j] = 1;
                    ans[i][j] = 0;
                    q.push({{i, j}, 0});
                }
            }
        }

        vector<int> delRow = {-1, 1, 0, 0};
        vector<int> delCol = {0, 0, -1, 1};

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;

            int dis = q.front().second;
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nRow = row + delRow[d];
                int nCol = col + delCol[d];

                if (nRow >= 0 && nRow < mat.size() && nCol >= 0 &&
                    nCol < mat[0].size() && vis[nRow][nCol] == 0) {
                    ans[nRow][nCol] = dis + 1;
                    vis[nRow][nCol] = 1;
                    q.push({{nRow, nCol}, dis + 1});
                }
            }
        }
        return ans;
    }
};