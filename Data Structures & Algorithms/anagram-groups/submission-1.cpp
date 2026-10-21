class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // map<vector<int>,vector<string>> m;
        unordered_map<string, vector<string>> m;

        for(auto str: strs){
            // vector<int> dic(26,0);
            string dic(26,0);
            for(auto j: str)
                dic[j-'a']++;
            
            m[dic].push_back(str);
        }

        vector<vector<string>> res;
        for(auto i: m){
            res.push_back(i.second);
        }
        return res;
    }
};
