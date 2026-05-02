class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> score(n + 1, 0);
        vector<vector<int>> isConnected(n + 1, (vector<int>(n + 1, 0)));
        for (auto& x : roads) {
            int u = x[0];
            int v = x[1];

            score[u]++;
            score[v]++;
            isConnected[u][v] = 1;
            isConnected[v][u] = 1;
        }
        int maxRank = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = score[i] + score[j];
                if (isConnected[i][j])
                    rank--;
                maxRank = max(maxRank, rank);
            }
        }

        return maxRank;
    }
};