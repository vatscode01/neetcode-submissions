class Solution {
   public:
    string minWindow(string s, string t) {
        vector<int> m(256, 0), ref(256, 0);
        if (t.size() > s.size()) return "";
        int startIdx = 0, minLen = s.size() + t.size();
        for (auto i : t) 
            ref[i]++;
            
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            m[s[j]]++;
            while (compare(m, ref) && i <= j) {
                if (minLen > j - i + 1) {
                    minLen = j - i + 1;
                    startIdx = i;
                }
                m[s[i]]--;
                i++;
            }
        }
        return minLen == s.size() + t.size() ? "" : s.substr(startIdx, minLen);
    }
    bool compare(vector<int>& m, vector<int>& ref) {
        for (int i = 0; i < 256; i++) {
            if (ref[i] > m[i]) return false;
        }
        return true;
    }
};
