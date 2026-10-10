class Solution {
public:
    int rob(vector<int>& nums) {
        // Self Solved

        int n = nums.size();
        if(n==1)    return nums[0];
        
        int pick=0,np=0;
        
        int a = func(nums,0,n-2);
        int b = func(nums,1,n-1);

        return max(a,b);

    }
    int func(vector<int> &nums, int low, int high){
        int pick = 0, np=0;

        for(int i=low; i<=high; i++){
            int sum = np + nums[i];
            np = max(pick,np);
            pick = sum;
        }
        return max(pick,np);
    }
};
