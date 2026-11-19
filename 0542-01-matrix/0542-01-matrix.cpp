class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // {{r,c},step}
        queue<pair< pair<int,int>, int>>q;
        vector<vector<int>>visited(m, vector<int>(n, 0));

        // queue initilization
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    visited[i][j] =1;
                }
            }
        }

        // traversing the queue
        vector<int>drow = {-1, 1, 0, 0};
        vector<int>dcol = {0, 0, 1, -1};


        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int step = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(
                    nrow >=0 && nrow <m && ncol >=0 && ncol <n
                    && !visited[nrow][ncol] 
                    && mat[nrow][ncol] !=0
                ){
                    visited[nrow][ncol] =1;
                    q.push({{nrow, ncol}, step+1});
                    mat[nrow][ncol] = step+1;
                }
            }
        }

        return mat;
    }
};