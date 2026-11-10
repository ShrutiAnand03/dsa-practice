class Solution {
public:
    bool dfs(
        int m,
        int n,
        int sr, 
        int sc,
        vector<vector<int>>& visited,
        vector<vector<int>>& grid
    ){
        if(sr<0 || sr>=m || sc<0 || sc>=n) return false;
        if(visited[sr][sc]) return true;
        if(grid[sr][sc] == 1) return true;

        if(sr == 0 || sr == m-1 || sc == 0 || sc == n-1) return false;

        visited[sr][sc] =1;
        bool up = dfs(m,n,sr-1,sc,visited,grid);
        bool down = dfs(m,n,sr+1,sc,visited,grid);
        bool left =dfs(m,n,sr,sc-1,visited,grid);
        bool right = dfs(m,n,sr,sc+1,visited,grid);

        return up && down && left && right;

    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int closedIslands =0;

        vector<vector<int>>visited(m, vector<int>(n,0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(
                    grid[i][j] != 1 
                    && !visited[i][j]
                ){
                    if(dfs(m,n,i,j,visited,grid)){
                        closedIslands++;
                    }
                }
            }
        }

        return closedIslands;
    }
};