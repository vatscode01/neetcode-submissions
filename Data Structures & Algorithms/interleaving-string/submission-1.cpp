class Solution {
   public:
    bool isInterleave(string a, string b, string c) {
        if (a.size() + b.size() != c.size()) return 0;
        
        vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,-1));

        return func(a,b,c,0,0,0,dp);
    }
    bool func(string a, string b, string c, int i, int j, int k, vector<vector<int>> &dp) {
        if (i == a.size() && j == b.size() && k == c.size()) return true;

        bool res = false;

        if(dp[i][j] != -1)  return dp[i][j];

        if (a[i] == b[j] == c[k])
            res = func(a, b, c, i + 1, j, k + 1, dp) || func(a, b, c, i, j + 1, k + 1, dp);
        if (a[i] == c[k]) 
            res = func(a, b, c, i + 1, j, k + 1, dp);
        if (b[j] == c[k]) 
            res = func(a, b, c, i, j + 1, k + 1, dp);

        return dp[i][j] = res;
    }
};
