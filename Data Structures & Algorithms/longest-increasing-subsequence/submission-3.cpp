class Solution {
   public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<int> curr(n+1,0),nxt(n+1,0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j >= -1; j--) {
                int pick = -1e9;
                if (j == -1 || a[i] > a[j]) 
                    pick = 1 + nxt[i + 1];

                int np = nxt[j + 1];

                curr[j + 1] = max(pick, np);
            }
            nxt = curr;
        }
        return curr[0];
    }
};
