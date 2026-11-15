class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        unordered_set<int> s;
        int res = 1;
        for (auto i : nums) s.insert(i);

        for (auto i : nums) {
            if (s.count(i + 1) && !s.count(i - 1)) {
                int count = 1, num = i;
                while (s.count(num + 1)) {
                    num = num + 1;
                    count++;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};
