class Solution {
   public:
    int total_sum;
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        total_sum = accumulate(nums.begin(), nums.end(),0);
        vector<vector<long long>> dp(n + 1, vector<long long>(total_sum * 2 + 1, -1));
        return func(nums, 0, 0, target, dp);
    }
    int func(vector<int>& nums, int i, long long sum, int target, vector<vector<long long>>& dp) {
        if (i == nums.size()) return sum == target;

        if (dp[i][sum + total_sum] != -1) 
            return dp[i][sum + total_sum];

        dp[i][sum + total_sum] = func(nums, i + 1, sum + nums[i], target, dp) +
                                 func(nums, i + 1, sum - nums[i], target, dp);

        return dp[i][sum + total_sum];
    }
};
