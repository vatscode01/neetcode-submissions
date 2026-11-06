class Solution {
   public:
#define ll long long
    int change(int amount, vector<int>& a) {
        int n = a.size();
        // vector<vector<ll>> dp(n + 1, vector<ll>(amount + 1, 0));
        // vector<int> curr(amount+1,0), next(amount+1,0);
        // for (int i = 0; i <= n; i++) {
        //     next[amount] = 1;
        // }

        vector<int> dp(amount+1,0);
        dp[0] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for(int sum = 0; sum<=amount; sum ++){
                if(sum - a[i] >= 0)
                    dp[sum] = dp[sum] + dp[sum - a[i]];
            }
        }
        return dp[amount];
    }
};
