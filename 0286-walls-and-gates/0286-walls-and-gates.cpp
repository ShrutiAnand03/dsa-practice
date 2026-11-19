class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        int n = rooms[0].size();

        // {{r,c},step}
        queue<pair< pair<int,int>, int>>q;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        // initialization
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(rooms[i][j] == 0){
                    visited[i][j] =1;
                    q.push({{i,j},0});
                }
            }
        }

        // queue loop
        vector<int> drow = {-1, 1, 0, 0};
        vector<int> dcol = {0, 0, -1, 1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int step = q.front().second;

            q.pop();

            for(int i=0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(
                    nrow>=0 && nrow<m && ncol >=0 && ncol<n
                    && !visited[nrow][ncol]
                    && rooms[nrow][ncol]!=-1
                ){
                    visited[nrow][ncol] =1;
                    q.push({{nrow, ncol}, step+1});
                    rooms[nrow][ncol] = step+1;
                }
            }

        }
    }
};