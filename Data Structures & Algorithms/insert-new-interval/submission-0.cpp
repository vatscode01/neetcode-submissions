class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0, n = a.size();
        while (i < n && a[i][1] < newInterval[0]) {
            res.push_back(a[i]);
            i++;
        }
        while (i < n && a[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], a[i][0]);
            newInterval[1] = max(newInterval[1], a[i][1]);
            i++;
        }
        res.push_back(newInterval);

        while (i < n) 
            res.push_back(a[i++]);

        return res;
    }
};
