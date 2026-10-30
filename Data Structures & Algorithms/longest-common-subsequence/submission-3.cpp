class Solution {
   public:
    // Space Optimisation
    // Self 
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int> curr(m + 1, 0), prev(m + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int res = 0;
                if (s1[i - 1] == s2[j - 1])
                    res = 1 + prev[j - 1];
                else
                    res = max(prev[j], curr[j - 1]);

                curr[j] = max(curr[j], res);
            }
            prev = curr;
        }
        return curr[m];
    }
};
