class Solution {
public:
    bool dfs(
        int src, 
        vector<vector<int>>& graph, 
        vector<int>& visited,
        int color
    ){
        visited[src] =color;

        for(auto &v: graph[src]){
            if(!visited[v]){
                bool ans = dfs(v, graph, visited, 3-color);
                if(!ans) return false;
            }
            else if(visited[v] == visited[src]) return false;
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>visited(n, 0);

        for(int i=0; i<n; i++){  
            if(!visited[i]){
                int ans = dfs(i, graph, visited, 1);
                if(!ans) return false;
            }
        }

        return true;
    }
};