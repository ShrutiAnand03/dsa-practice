class Solution {
public:
    bool dfs(
        int src, 
        vector<int>& visited,
        vector<vector<int>>& graph,
        int color
    ){
        visited[src] =color;
        for(auto v: graph[src]){
            if(!visited[v]){
                if(!dfs(v, visited, graph, 3-color)) return false;
            }
            else if(visited[src] == visited[v]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>visited(v, 0);

        for(int i =0; i<v; i++){
            if(!visited[i]){
                bool ans = dfs(i, visited, graph, 1);
                if(!ans) return false;
            }
        }

        return true;
    }
};