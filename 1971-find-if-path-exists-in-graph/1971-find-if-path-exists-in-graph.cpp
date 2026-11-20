class Solution {
public:
    bool dfs(
        int source, 
        int destination, 
        vector<vector<int>>& adj, 
        vector<int>& visited
    ){
        visited[source] =1;

        for(auto &v: adj[source]){
            if(!visited[v]){
                if(v == destination) return true;
                bool ans =dfs(v, destination, adj, visited);
                if(ans) return true;
            }
        }

        return false;
    }
    vector<vector<int>> createGraph(int n, vector<vector<int>>& edges){

        vector<vector<int>>adj(n);

        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj = createGraph(n, edges);
        vector<int>visited(n, 0);
        
        if(source == destination) return true;
        return dfs(source, destination, adj, visited);
    }
};