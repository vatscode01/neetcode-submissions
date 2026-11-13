class Solution {
   public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return func(s, t, 0, 0, dp);
    }
    int func(string s, string t, int i, int j, vector<vector<int>>& dp) {
        if (j >= t.size()) return 1;
        if (i >= s.size()) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int res = 0;
        for (int k = i; k < s.size(); k++) {
            if (s[k] == t[j]) res += func(s, t, k + 1, j + 1, dp);
        }
        return dp[i][j] = res;
    }
};
