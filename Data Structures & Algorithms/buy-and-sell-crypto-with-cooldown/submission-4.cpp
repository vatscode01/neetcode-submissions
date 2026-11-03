class Solution {
   public:
   // Don't jump directly to this solution.
    int maxProfit(vector<int>& a) {
        int n = a.size();
        // vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        vector<int> curr(2, 0), next(2, 0), supnext(2, 0);
        int profit = 0;
        for (int i = n - 1; i >= 0; i--) {
            int hold_buy = next[1];
            int buy = -a[i] + next[0];
            curr[1] = max(hold_buy, buy);

            int hold_selling = next[0];
            int sell = a[i] + supnext[1];
            curr[0] = max(hold_selling, sell);

            supnext = next;
            next = curr;
        }
        return curr[1];
    }
};
