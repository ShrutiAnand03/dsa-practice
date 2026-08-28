class Solution {
public:
    void dfs(
        int src,
        int target,
        vector<vector<int>>& graph,
        vector<int>& visited,
        vector<int>path,
        vector<vector<int>>& allPath

    ){
        visited[src] =1;
        path.push_back(src);

        if (src == target){
            allPath.push_back(path);
        }
        for(auto v: graph[src]){
            if(!visited[v]){
                dfs(v, target, graph, visited, path, allPath);
            }
        }
        path.pop_back();
        visited[src] =0;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>allPath;
        vector<int>visited(n, 0);
        vector<int>path;
        dfs(0, n-1, graph, visited, path, allPath);
        return allPath;
    }
};