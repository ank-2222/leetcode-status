class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& vis,
             vector<vector<char>>& board, vector<int>& delRow,
             vector<int>& delCol) {
        vis[i][j] = 1;
        for (int d = 0; d < 4; d++) {
            int nRow = i + delRow[d];
            int nCol = j + delCol[d];

            if (nRow >= 0 && nRow < board.size() && nCol >= 0 &&
                nCol < board[0].size() && vis[nRow][nCol] == 0 &&
                board[nRow][nCol] == 'O') {
                dfs(nRow, nCol, vis, board, delRow, delCol);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        vector<int> delRow = {-1, 1, 0, 0};
        vector<int> delCol = {0, 0, -1, 1};

        for (int i = 0; i < m; i++) {
            if (vis[i][0] == 0 && board[i][0] == 'O') {
                dfs(i, 0, vis, board, delRow, delCol);
            }

            if (vis[i][n - 1] == 0 && board[i][n - 1] == 'O') {
                dfs(i, n - 1, vis, board, delRow, delCol);
            }
        }

        for (int i = 0; i < n; i++) {
            if (vis[0][i] == 0 && board[0][i] == 'O') {
                dfs(0, i, vis, board, delRow, delCol);
            }

            if (vis[m - 1][i] == 0 && board[m - 1][i] == 'O') {
                dfs(m - 1, i, vis, board, delRow, delCol);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((vis[i][j] == 0 && board[i][j] == 'O')) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};