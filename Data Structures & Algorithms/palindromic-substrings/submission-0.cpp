class Solution {
   public:
    int countSubstrings(string s) {
        int count = 0, n = s.size();

        for (int mid = 0; mid < n; mid++) {
            int i = mid, j = mid;
            while (i >= 0 && j < n && s[i] == s[j]) {
                count++;
                i--;
                j++;
            }
            i = mid, j = mid + 1;
            while (i >= 0 && j < n && s[i] == s[j]) {
                count++;
                i--;
                j++;
            }
        }
        return count;
    }
};
