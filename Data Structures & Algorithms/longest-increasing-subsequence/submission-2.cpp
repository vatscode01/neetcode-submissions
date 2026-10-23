class Solution {
   public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j >= -1; j--) {
                int pick = -1e9;
                if (j == -1 || a[i] > a[j]) 
                    pick = 1 + dp[i + 1][i + 1];

                int np = dp[i + 1][j + 1];

                dp[i][j + 1] = max(pick, np);
            }
        }
        return dp[0][0];
    }
};
