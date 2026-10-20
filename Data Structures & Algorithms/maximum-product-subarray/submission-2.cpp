class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Kadene's Algorithm (Copied)
        int currMax = 1, currMin = 1, res=nums[0];
        for(int i=0; i<nums.size(); i++){
            int temp = currMax * nums[i];
            currMax = max(max(currMax * nums[i], currMin * nums[i]), nums[i]);
            currMin = min(min(currMin * nums[i], temp), nums[i]);
            
            res = max(res, currMax);
        }
        return res;
    }
};
