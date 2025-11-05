class Solution {
      vector<vector<int>> direction = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    bool solve(vector<vector<char>>& board, string word, int i, int j,
               int index) {
        if (board[i][j] != word[index])
            return false;
        if (index == word.length() - 1) {
            return true;
        }
        char ch = board[i][j];  //current cell weare checking and changing here itself
        board[i][j] = '#';   //marking visited
        for (int k = 0; k < 4; k++) {
            int newRow = direction[k][0] + i;
            int newColumn = direction[k][1] + j;
            if (newRow >= 0 && newRow < board.size() && newColumn >= 0 &&
                newColumn < board[0].size() &&
                board[newRow][newColumn] != '#') {

                if (solve(board, word, newRow, newColumn, index + 1)) {
                    board[i][j] = ch;
                    return true;
                }
            }
        }
        board[i][j] = ch;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (solve(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};