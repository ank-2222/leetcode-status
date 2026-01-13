class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& ans,
             vector<vector<int>>& image, vector<int> delRow, vector<int> delCol,
             int newColor,int iniclr) {

        // color initial point
        ans[row][col] = newColor;

        for (int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            // check bound
            if (nRow >= 0 && nRow < image.size() && nCol >= 0 &&
                nCol < image[0].size()) {

                if (image[nRow][nCol] == iniclr && ans[nRow][nCol] != newColor) {
                    ans[nRow][nCol] = newColor;
                    dfs(nRow, nCol, ans, image, delRow, delCol, newColor,iniclr);
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int iniclr = image[sr][sc];
        vector<vector<int>> ans = image;
        vector<int> delRow = {-1, 1, 0, 0};
        vector<int> delCol = {0, 0, -1, 1};
        dfs(sr, sc, ans, image, delRow, delCol, color,iniclr);
        return ans;
    }
};