class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int V = edges.size()-1;
        vector<vector<int>> adj(V+2);
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);

            vector<int> vis(V+2,0);
            if(isCycle(adj,vis,e[0],-1))
                return e;
        }
        return {};
    }
    bool isCycle(vector<vector<int>> &adj, vector<int> &vis,
    int idx, int parent){
        if(vis[idx])    return 1;
        vis[idx] = 1;
        for(int i: adj[idx]){
            if(i == parent) continue;
            if(isCycle(adj,vis,i,idx))     
                return true;
        }
        return false;
    }
};
