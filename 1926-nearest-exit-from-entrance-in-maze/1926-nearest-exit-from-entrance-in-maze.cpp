class Solution {
public:
    int minSteps(
        int m, 
        int n, 
        vector<vector<char>>& maze, 
        vector<int>& entrance
    ){
        vector<vector<int>> visited(m, vector<int>(n, 0));

        // {{r, c}, step}
        queue<pair< pair<int,int>,int>>q;

        // initialisation
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(maze[i][j] == '.'){
                    // check for the boundry conditions

                    if( (i==0 || i== m-1 || j==0 || j == n-1)
                        && !(i==entrance[0] && j==entrance[1])
                    ){
                        q.push({{i, j}, 0});
                        visited[i][j] =1;
                    }
                }
            }
        }

        int stepmin  =-1;
        vector<int>drow = {-1, 1, 0, 0};
        vector<int>dcol = {0, 0, -1, 1};

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
                    && maze[nrow][ncol]!= '+'
                ){
                    q.push({{nrow, ncol}, step+1});
                    visited[nrow][ncol] =1;

                    if(nrow == entrance[0] && ncol == entrance[1]){
                        stepmin = step+1;
                        cout<<"stepmin"<<stepmin<<"\n";
                    }
                }
            }

        }

        return stepmin;   
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        if(m == 1 && n == 1) return -1;

        return minSteps(m,n,maze,entrance);
    }
};