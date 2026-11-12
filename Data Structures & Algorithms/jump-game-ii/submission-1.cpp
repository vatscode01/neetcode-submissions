class Solution {
   public:
    int jump(vector<int>& nums) {
        int i = 0, n = nums.size(), l = 0, r = 0, count = 0;
        while (r < n - 1) {
            int farthest = r;
            for (i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            l = r + 1;
            r = farthest;
            count++;
        }
        return count;
    }
};
