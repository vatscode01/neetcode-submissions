class Solution {
   public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return func(nums, 0, 1, dp);
    }
    int func(vector<int>& a, int i, bool canBuy, vector<vector<int>>& dp) {
        int res = 0, n = a.size();

        if (i >= n) return 0;
        if (dp[i][canBuy] != -1) return dp[i][canBuy];

        int profit = 0;
        if (canBuy) {
            int hold = func(a, i + 1, 1, dp);
            int buy = -a[i] + func(a, i + 1, 0, dp);
            profit = max(hold, buy);
        } else {
            int hold = func(a, i + 1, 0, dp);
            int sell = a[i] + func(a, i + 2, 1, dp);
            profit = max(hold, sell);
        }
        return dp[i][canBuy] = profit;
    }
};
