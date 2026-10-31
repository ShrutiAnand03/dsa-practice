class Solution {
public:
    bool dfs(
        vector<vector<int>>& graph,
        vector<int>& visited,
        int color,
        int src
    ){
        visited[src] = color;
        for(auto &v: graph[src]){
            if(!visited[v]){
                if(!dfs(graph, visited, 3-color, v)){
                    return false;
                }
            }
            else if(visited[src] == visited[v]){
                return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>visited(v, 0);
        bool ans = true;

        for(int i=0; i<v; i++){
            if(!visited[i]){
                ans = dfs(graph, visited, 1, i);
                if(!ans) return false;
            }
        }
        return ans;
    }
};