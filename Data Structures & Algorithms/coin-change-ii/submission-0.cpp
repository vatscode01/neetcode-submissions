class Solution {
   public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
        return func(coins, amount, 0, 0, dp);
    }
    int func(vector<int>& a, int amount, int sum, int i, vector<vector<int>>& dp) {
        if (i >= a.size() || sum > amount) return 0;
        if (sum == amount) return 1;

        if (dp[i][sum] != -1) return dp[i][sum];
        return dp[i][sum] = func(a, amount, sum, i + 1, dp) + func(a, amount, sum + a[i], i, dp);
    }
};
