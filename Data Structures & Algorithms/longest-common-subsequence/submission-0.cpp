class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size(),m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return func(text1,text2,dp,n-1,m-1);
    }
    int func(string s1, string s2, vector<vector<int>> &dp, int i, int j){
        if(i<0 || j<0)  return 0;
        if(dp[i][j] != -1)  return dp[i][j];

        int res = 0;
        if(s1[i] == s2[j])
            res = 1 + func(s1,s2,dp,i-1,j-1);
        else
            res = max(func(s1,s2,dp,i-1,j),func(s1,s2,dp,i,j-1));
        
        return dp[i][j] = res;
    }
};
