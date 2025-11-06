class Solution {

    bool isSafe(int row, int col, vector<bool>& usedCol,
                vector<bool>& usedMajorDiagonal,
                vector<bool>& usedMinorDiagonal, int n) {
        int majorDiagonal =
            row - col +
            n; // to come out of negatives due to large of of col than row,
        int minorDiagonal = row + col;
        return !usedCol[col] && !usedMajorDiagonal[majorDiagonal] &&
               !usedMinorDiagonal[minorDiagonal];
    }

    void solve(int n, vector < vector < string >> &ans, vector<string>& board,
               int row, vector<bool>& usedCol, vector<bool>& usedMajorDiagonal,
               vector<bool>& usedMinorDiagonal) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (isSafe(row, i, usedCol, usedMajorDiagonal, usedMinorDiagonal,
                       n)) {
                usedCol[i] = true;
                usedMajorDiagonal[row - i + n] = true;
                usedMinorDiagonal[row + i] = true;
                board[row][i] = 'Q';
                solve(n, ans, board, row + 1, usedCol, usedMajorDiagonal,
                      usedMinorDiagonal);
                board[row][i] = '.';
                usedCol[i] = false;
                usedMajorDiagonal[row - i + n] = false;
                usedMinorDiagonal[row + i] = false;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<bool> usedCol(n, false);

        vector<bool> usedMajorDiagonal(2 * n, false);
        vector<bool> usedMinorDiagonal(2 * n, false);
        vector<string> board(n, string(n, '.'));

        solve(n, ans, board, 0, usedCol, usedMajorDiagonal, usedMinorDiagonal);
        return ans;
    }
};