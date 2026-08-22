class Solution {
public:
    int bfs(
        int sr, 
        int sc, 
        int m,
        int n,
        vector<vector<char>>& grid, 
        vector<vector<int>>& visited
    ){
        queue<pair<int,int>>q;
        visited[sr][sc] = 1;
        q.push({sr, sc});

        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;

            vector<int>dr = {-1, 1, 0, 0};
            vector<int>dc = {0, 0, -1, 1};

            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr <0 || nc <0 || nr>=m || nc>=n) continue;
                if(visited[nr][nc]) continue;
                if(grid[nr][nc] == '0') continue;

                visited[nr][nc] =1;
                q.push({nr,nc});
            }
        }

        return 1;

    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m, vector<int>(n, 0));
        int count =0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    count+= bfs(i,j,m,n,grid,visited);
                }
            }
        }

        return count;
    }
};


// [(0,0), (0,1), (1,0)]
// [(0,1), (1,0), (0,2), (1,1)]
// [(1,0), (0,2), (1,1), (2,0)]
// [(0,2), (1,1), (2,0), (0,3)]
// [(1,1), (2,0), (0,3), (2,1)]
// [(2,0), (0,3), (2,1)]
// [(0,3), (2,1), (1,3)]
// [(2,1), (1,3)]
// [(1,3)]
// []