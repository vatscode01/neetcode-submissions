class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& word) {
        unordered_set<string> st(word.begin(),word.end());
        queue<pair<string,int>> q;
        q.push({begin,1});
        st.erase(begin);

        while(!q.empty()){
            auto [w,d] = q.front();
            if(w == end) return d;

            for(int i=0; i<w.size(); i++){
                for(char c='a'; c<='z'; c++){
                    w[i] = c;
                    if(st.find(w)!=st.end()){
                        q.push({w,d+1});
                        st.erase(w);
                    }
                }
                w = q.front().first;
            }
            q.pop();
        }
        return 0;
    }
};