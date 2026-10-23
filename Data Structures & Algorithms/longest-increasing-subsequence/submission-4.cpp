class Solution {
   public:
    // One more approach of space optimisation:
    // TC : O(n^2)
    // TC : O(2 * n) = O(n)
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(2, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j >= -1; j--) {
                int pick = -1e9;
                if (j == -1 || a[i] > a[j]) pick = 1 + dp[1][i + 1];

                int np = dp[1][j + 1];

                dp[0][j + 1] = max(pick, np);
            }
            dp[1] = dp[0];
        }
        return dp[0][0];
    }
};
