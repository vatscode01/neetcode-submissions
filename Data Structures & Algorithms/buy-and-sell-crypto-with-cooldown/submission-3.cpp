class Solution {
   public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        // vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        vector<int> curr(2, 0), next(2, 0), supnext(2, 0);
        int profit = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                if (canBuy) {
                    int hold = next[1];
                    int buy = -a[i] + next[0];
                    profit = max(hold, buy);
                } else {
                    int hold = next[0];
                    int sell = a[i] + supnext[1];
                    profit = max(hold, sell);
                }
                curr[canBuy] = max(curr[canBuy], profit);
            }
            supnext = next;
            next = curr;
        }
        return curr[1];
    }
};
