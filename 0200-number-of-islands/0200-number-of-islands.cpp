class Solution {
public:
    void dfs(
        int m,
        int n,
        int sr,
        int sc,
        vector<vector<char>>& grid,
        vector<vector<int>>& visited
    ){
        if(sr <0 || sr>=m || sc<0 || sc>=n) return;
        if(visited[sr][sc]==1) return;
        if(grid[sr][sc]=='0') return;

        visited[sr][sc] =1;

        dfs(m, n, sr-1, sc, grid, visited);
        dfs(m, n, sr+1, sc, grid, visited);
        dfs(m, n, sr, sc-1, grid, visited);
        dfs(m, n, sr, sc+1, grid, visited);

    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m, vector<int>(n,0));

        int count =0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(
                    grid[i][j]!='0' && 
                    visited[i][j]!=1
                ){
                    dfs(m, n, i, j, grid, visited);
                    count++;
                }
            }
        }

        return count;
    }
};