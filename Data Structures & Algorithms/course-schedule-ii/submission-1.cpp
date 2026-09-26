class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& matrix) {
        vector<int> vis(n, 0), completed(n, 0), res;

        vector<vector<int>> graph(n);
        for (auto i : matrix)
            graph[i[0]].push_back(i[1]);

        for (int i = 0; i < n; i++) {
            if (!completed[i])
                if (!dfs(n, graph, vis, completed, i, res))
                    return {};
        }
        return res;
    }
    bool dfs(int n, vector<vector<int>>& graph, vector<int>& vis,
             vector<int>& completed, int idx, vector<int> &res) {
        if (vis[idx])
            return false;
        if (completed[idx])
            return true;

        vis[idx] = 1;
        for (int i = 0; i < graph[idx].size(); i++) {
            if (!dfs(n, graph, vis, completed, graph[idx][i], res)) {
                return false;
            } 
        }
        vis[idx] = 0;
        res.push_back(idx);
        return completed[idx] = true;
    }
};
 