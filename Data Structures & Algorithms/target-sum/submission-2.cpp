class Solution {
    // Tabulation
   public:
    int total_sum;
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        total_sum = accumulate(nums.begin(), nums.end(), 0);
        // vector<vector<long long>> dp(n + 1, vector<long long>(total_sum * 2 + 1, 0));

        if((total_sum + target)%2 != 0)     return 0;
        target = (total_sum + target) / 2;
        if(target < 0)      return 0;

        return countSubsetSum(nums,target);
    }

    int countSubsetSum(vector<int>& arr, int target) {
		// code here
		int n = arr.size();

        vector<int> curr(target+1,0), next(target+1,0);
		
		for (int i = 0; i <= n; i++) {
			next[0] = 1;
		}
		
		for (int i = n - 1; i >= 0; i--) {
			for (int sum = 0; sum <= target; sum++) {
				int np = next[sum];
				int pick = (sum - arr[i] >= 0) ? next[sum - arr[i]] : 0;
				curr[sum] = pick + np;
			}
			next = curr;
		}
		return curr[target];
		
	}
};
