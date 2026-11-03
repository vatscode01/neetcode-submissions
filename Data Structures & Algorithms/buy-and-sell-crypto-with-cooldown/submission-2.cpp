class Solution {
   public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        int profit = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                if (canBuy) {
                    int hold = dp[i + 1][1];
                    int buy = -a[i] + dp[i + 1][0];
                    profit = max(hold, buy);
                } else {
                    int hold = dp[i + 1][0];
                    int sell = a[i] + dp[i + 2][1];
                    profit = max(hold, sell);
                }
                dp[i][canBuy] = max(dp[i][canBuy], profit);
            }
        }
        return dp[0][1];
    }
};
