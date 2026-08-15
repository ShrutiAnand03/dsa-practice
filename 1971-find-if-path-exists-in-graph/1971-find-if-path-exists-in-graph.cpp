class Solution {
public:

    void bfs(
        vector<int>&visited, 
        vector<vector<int>>adj, 
        int source
    ){
        queue<int>q;

        q.push(source);
        visited[source] =1;


        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(auto v: adj[curr]){
                if(!visited[v]){
                    visited[v] =1;
                    q.push(v); 
                }
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>visited(n, 0);
        bfs(visited, adj, source);

        if (visited[destination] == 1) return 1;
        return 0; 
        
    }
};