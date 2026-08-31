class Solution {
public:
    void dfs(
        int src,
        int n,
        vector<int>& path,
        vector<int>& visited,
        vector<vector<int>>& allPath,
        vector<vector<int>>& graph
    ){
        visited[src]=1;
        path.push_back(src);

        if(src == n-1){
            allPath.push_back(path);
        }

        for(auto v: graph[src]){
            if(!visited[v]){
                dfs(v, n, path, visited, allPath, graph);
            }
        }

        visited[src] =0;
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>>allPath;
        vector<int>path;
        vector<int>visited(n, 0);

        dfs(0, n, path, visited, allPath, graph);
        return allPath;
    }
};