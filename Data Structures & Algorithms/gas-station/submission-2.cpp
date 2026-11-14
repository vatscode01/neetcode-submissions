class Solution {
   public:
   // Self
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        pair<int, int> maxi = {INT_MIN, -1};
        int n = gas.size(), count = 0, sum = 0, idx = 0, total_sum=0;

        for(int i=0; i<n; i++){
            int diff = gas[i] - cost[i];
            total_sum += diff;
            sum += diff;
            if(sum < 0){
                sum = 0;
                idx = i+1;
            }
        }
        if(total_sum < 0)   return -1;
        return idx == n ? -1 : idx;
    }
};
