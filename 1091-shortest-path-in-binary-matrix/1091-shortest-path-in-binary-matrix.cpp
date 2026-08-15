class Solution {
public:
    int bfs(vector<vector<int>>& grid, int n){
        queue<pair<int,int>>q;
        vector<vector<int>> visited(n, vector<int>(n,0));
        vector<vector<int>> distance(n, vector<int>(n,0));


        visited[0][0] =1;
        distance[0][0] =1;
        q.push({0,0});

        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();

            int r = curr.first;
            int c = curr.second;


            if (r == n - 1 && c == n - 1) {
                return distance[r][c];
            }

            vector<int>dr = {-1, 1, 0, 0, -1, 1, -1, 1};
            vector<int>dc = {0, 0, -1, 1, -1, 1, 1, -1};

            for(int i=0; i<8; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr<0 || nc<0 || nr >=n || nc>=n){
                    continue;
                }

                if(visited[nr][nc] == 1) continue;
                if(grid[nr][nc] == 1) continue;

                visited[nr][nc] =1;
                distance[nr][nc] = distance[r][c] + 1;
                q.push({nr, nc});
            }

        }

        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(
            grid[0][0] == 1 || 
            grid[n-1][n-1] == 1
        ) return -1;

        return bfs(grid, n);

    }
};