class Solution {
public:
    bool validTree(int n, vector<vector<int>>& e) {
        if(e.size() != n-1 || isCycle(n,e))     return false;
        return true;
    }
    bool isCycle(int n, vector<vector<int>> & edges) {
		// Code here
		vector<int> vis(n, 0);
		unordered_map<int, vector<int>> m;
		for (int i = 0; i < edges.size(); i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			
			m[u].push_back(v);
			m[v].push_back(u);
		}
		for (int i = 0; i<n; i++) {
			if (!vis[i])
				if (dfs(i,-1, m, vis))
				return true;
		}
		return false;
	}
	bool dfs(int idx,int parent, unordered_map<int, vector<int>> &m, vector<int>&vis) {
		if(vis[idx])  return true;
		vis[idx] = 1;
		for (int i = 0; i<m[idx].size(); i++) {
		    if(m[idx][i] == parent) continue;
			if (dfs(m[idx][i], idx, m, vis))
				return true;
		}
		
		return false;
	}
};
