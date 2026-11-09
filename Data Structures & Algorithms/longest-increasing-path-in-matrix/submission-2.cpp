class Solution {
   public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        vector<vector<int>> indegree(n, vector<int>(m, 0));
        vector<vector<int>> dp(n, vector<int>(m, 1));

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        queue<pair<int, int>> q;

        // Calculate indegrees
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if (x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] < matrix[i][j]) {
                        indegree[i][j]++;
                    }
                }

                if (indegree[i][j] == 0) q.push({i, j});
            }
        }

        int ans = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [i, j] = q.front();
                q.pop();

                ans = max(ans, dp[i][j]);

                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if (x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] > matrix[i][j]) {
                        dp[x][y] = max(dp[x][y], dp[i][j] + 1);

                        indegree[x][y]--;

                        if (indegree[x][y] == 0) q.push({x, y});
                    }
                }
            }
        }

        return ans;
    }
};
