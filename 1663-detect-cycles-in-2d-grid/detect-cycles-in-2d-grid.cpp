class Solution {
    struct Node {
        int r, c;   // current row, col
        int pr, pc; // parent row col
    };

public:
    bool cyclePresent(int i, int j, int m, int n, vector<vector<char>>& grid,
                      vector<vector<int>>& vis) {
        // traversing to next cell
        vector<int> delRow = {-1, 1, 0, 0};
        vector<int> delCol = {0, 0, -1, 1};

        queue<Node> q;
        q.push({i, j, -1, -1}); // inital cell
        vis[i][j] = 1;
        while (!q.empty()) {
            int r = q.front().r;
            int c = q.front().c;
            int pr = q.front().pr;
            int pc = q.front().pc;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nRow = r + delRow[i]; // new row
                int nCol = c + delCol[i]; // new col

                // bound check
                if (nRow >= 0 && nRow < grid.size() && nCol >= 0 &&
                    nCol < grid[0].size() && grid[nRow][nCol] == grid[r][c]) {
                    if (vis[nRow]
                           [nCol]) { // if encountered with visited, need to
                                     // check if thats parent or other, if not
                                     // parent that means some other branch of
                                     // bfs in graph has already visited it and
                                     // there is cycle
                        if (!(nRow == pr &&
                              nCol ==
                                  pc)) // here we have to check for both
                                       // simaltaneously, rather than checking
                                       // each , as it will do diagonal mismatch
                                       // (nRow != pr && nCol !=pc) is wrong
                            return true;
                    } else {
                        vis[nRow][nCol] = 1;
                        q.push({nRow, nCol, r, c});
                    }
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) { // starting from non visited, this helps in
                                  // comparing all component of graphs
                    if (cyclePresent(i, j, m, n, grid, vis)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};