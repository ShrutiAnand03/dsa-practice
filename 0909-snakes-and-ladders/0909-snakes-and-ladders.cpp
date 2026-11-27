class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int>connection(n*n+1, -1);
        bool flag = true;
        int node =1;

        // covert the 2d board in the simple list
        for(int i=n-1; i>=0; i--){
            if(flag){
                for(int j=0; j<n; j++){
                    if(board[i][j]!=-1){
                        connection[node] = board[i][j];
                    }
                    node++;
                }
            }
            else{
                for(int j=n-1; j>=0; j--){
                    if(board[i][j]!=-1){
                        connection[node] = board[i][j];
                    }
                    node++;
                }
            }

            flag = !flag;
        }


        // create the adjacency list
        vector<vector<int>>graph(n*n+1);
        for(int i=1; i<n*n; i++){
            for(int count =1; count<=6; count++){
                int nbr = i + count;
                
                if(nbr > n*n) break;

                if(connection[nbr]!=-1){
                    graph[i].push_back(connection[nbr]);
                }
                else{
                    graph[i].push_back(nbr);
                }
            }
        }

        // bfs 
        int level =0;
        vector<int>visited(n*n+1, 0);
        queue<int>q;
        q.push(1);
        visited[1]=1;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                int pos = q.front();
                q.pop();

                if(pos == n*n) return level;

                for(int nbr: graph[pos]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        visited[nbr] =1;
                    }
                }
            }
            level +=1;
        }

        return -1;
    }
};