class Solution {
public:
    void bfs(int i, int j, vector<vector<int>>& vis,
             vector<vector<char>>& grid) {

        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty()) {
            pair<int, int> frontNode = q.front();

            q.pop();
            int r = frontNode.first;
            int c = frontNode.second;

            // 4-direction movement
            int dr[4] = {-1, 1, 0, 0};
            int dc[4] = {0, 0, -1, 1};

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                // check bounds
                if (nr >= 0 && nr < grid.size() && nc >= 0 &&
                    nc < grid[0].size()) {

                    if (grid[nr][nc] == '1' && vis[nr][nc] == 0) {
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    count++;

                    bfs(i, j, vis, grid);
                }
            }
        }
        return count;
    }
};