class Solution {
public:
    bool dfs(
        int src,
        vector<int>& visited,
        vector<int>& current_path,
        vector<vector<int>>& graph
    ){
        visited[src] =1;
        current_path[src] =1;

        for(auto nbr: graph[src]){
            if(!visited[nbr]){
                bool isCycle = dfs(nbr, visited, current_path, graph);
                if(isCycle) return true;
            }
            else{
                if(current_path[nbr] ==1) return true;
            }
        }

        current_path[src] =0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>visited(n, 0);
        vector<int>current_path(n, 0);
        vector<int>ans;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                bool iscycle = dfs(i, visited, current_path, graph);
            }
        }

        for(int i=0;i<n;i++){
            cout<<current_path[i]<<" ";
            if(current_path[i]!=1) ans.push_back(i);
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};