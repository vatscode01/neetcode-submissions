class Solution {
   public:
#define ll long long
    int change(int amount, vector<int>& a) {
        int n = a.size();
        // vector<vector<ll>> dp(n + 1, vector<ll>(amount + 1, 0));
        vector<int> curr(amount+1,0), next(amount+1,0);
        for (int i = 0; i <= n; i++) {
            next[amount] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int sum = amount; sum >= 0; sum--) {
                long long np = next[sum];
                long long pick = (a[i] + sum <= amount) ? curr[sum + a[i]] : 0;
                curr[sum] = pick + np;
            }
            next = curr;
        }
        return curr[0];
    }
};
