class Solution {
   public:
    bool isInterleave(string a, string b, string c) {
        if (a.size() + b.size() != c.size()) return 0;
        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[n][m] = 1;

        for (int i = n; i >= 0; i--) {
            for (int j = m; j >= 0; j--) {
                if (i < n && a[i] == c[i + j]) 
                    dp[i][j] |= dp[i + 1][j];
                if (j < m && b[j] == c[i + j]) 
                    dp[i][j] |= dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};
