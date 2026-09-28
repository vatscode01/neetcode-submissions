class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0); int res =0;
        vector<vector<int>> graph(n);
        for(auto i: edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        for(int i=0; i<n; i++){
            if(!vis[i]){
                res ++;
                dfs(graph,vis,i);
            }
        }
        return res;
    }
    void dfs(vector<vector<int>> &graph, vector<int> &vis, int idx){
        if(vis[idx])  return;
        vis[idx] = 1;

        for(auto i: graph[idx]){
            dfs(graph,vis,i);
        }
    }
};
