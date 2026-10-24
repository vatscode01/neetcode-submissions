class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;

        for (auto i : nums) {
            if (dp.empty())
                dp.push_back(i);
            else {
                int idx = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
                if (idx == dp.size())
                    dp.push_back(i);
                else
                    dp[idx] = i;
            }
        }
        return dp.size();
    }
};
