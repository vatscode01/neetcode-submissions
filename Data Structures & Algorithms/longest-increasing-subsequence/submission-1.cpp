class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(1008, vector<int>(1008, -1));
        return func(nums, 0, -1, dp);
    }
    int func(vector<int>& a, int i, int prev_idx, vector<vector<int>>& dp) {
        if (i >= a.size()) return 0;
        if (dp[i][prev_idx + 1] != -1) return dp[i][prev_idx + 1];

        int pick = -1e9;
        if (prev_idx == -1 || a[i] > a[prev_idx]) pick = 1 + func(a, i + 1, i, dp);

        int np = func(a, i + 1, prev_idx, dp);

        return dp[i][prev_idx + 1] = max(pick, np);
    }
};
