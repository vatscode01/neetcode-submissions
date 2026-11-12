class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), k = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (i + nums[i] >= k) {
                k = i;
            }
        }
        return k == 0;
    }
};
