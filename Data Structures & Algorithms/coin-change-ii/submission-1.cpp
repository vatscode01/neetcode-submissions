class Solution {
   public:
#define ll long long
    int change(int amount, vector<int>& a) {
        int n = a.size();
        vector<vector<ll>> dp(n + 1, vector<ll>(amount + 1, 0));
        for (int i = 0; i <= n; i++) {
            dp[i][amount] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int sum = amount; sum >= 0; sum--) {
                long long np = dp[i + 1][sum];
                long long pick = (a[i] + sum <= amount) ? dp[i][sum + a[i]] : 0;
                dp[i][sum] = pick + np;
            }
        }
        return dp[0][0];
    }
};
