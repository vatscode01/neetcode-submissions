class Solution {
   public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
                res = max(res, func(matrix, i, j, -1e9, dp));
            }
        }
        return res;
    }
    int func(vector<vector<int>>& matrix, int i, int j, int ref, vector<vector<int>>& dp) {
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || matrix[i][j] <= ref)
            return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int a = func(matrix, i + 1, j, matrix[i][j], dp);
        int b = func(matrix, i - 1, j, matrix[i][j], dp);
        int c = func(matrix, i, j + 1, matrix[i][j], dp);
        int d = func(matrix, i, j - 1, matrix[i][j], dp);

        return dp[i][j] = 1 + max({a, b, c, d});
    }
};
