class Solution {
   public:
    int minDistance(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
        return func(s, t, 0, 0, dp);
    }
    int func(string s, string t, int i, int j, vector<vector<int>>& dp) {
        if (i >= s.size() || j >= t.size()) {
            int count = 0;
            while (i < s.size() || j < t.size()) {
                count++;
                if(i<s.size())
                    i++;
                if(j<t.size())
                    j++;
            }
            return count;
        }
        if (dp[i][j] != -1) return dp[i][j];

        int res;
        if (s[i] == t[j])
            res = func(s, t, i + 1, j + 1, dp);
        else {
            int c1 = func(s, t, i, j + 1, dp);      // Insert char
            int c2 = func(s, t, i + 1, j + 1, dp);  // Replace char
            int c3 = func(s, t, i + 1, j, dp);      // Delete char

            res = 1 + min({c1, c2, c3});
        }
        return dp[i][j] = res;
    }
};
