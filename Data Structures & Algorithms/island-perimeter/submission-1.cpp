class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1)
                    return func(grid, vis, i, j);
            }
        }
        return -1;
    }
    int func(vector<vector<int>> &grid, vector<vector<int>> &vis, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())  return 1;
        if(vis[i][j] == 1)    return 0;
        if(grid[i][j] == 0) return 1;
        vis[i][j] = 1; 

        return func(grid, vis, i-1,j) + func(grid, vis, i+1,j) + func(grid, vis, i,j-1) + func(grid, vis, i,j+1);
    }
};