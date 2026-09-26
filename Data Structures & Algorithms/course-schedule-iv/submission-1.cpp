class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& matrix, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);   vector<bool> res;
        for(auto i: matrix){
            graph[i[0]].push_back(i[1]);
        }
        for(auto q: queries){
            vector<int> vis(n,0);
            res.push_back(dfs(graph, q[0], q[1], vis));
        }
        return res;
    }
    bool dfs(vector<vector<int>> &graph, int idx, int target, vector<int> &vis){
        if(vis[idx])    return false;
        if(idx == target)   return true;
        vis[idx] = 1;

        for(auto x: graph[idx]){
            if(dfs(graph, x, target, vis))  return true;
        }

        return false;
    }   
};