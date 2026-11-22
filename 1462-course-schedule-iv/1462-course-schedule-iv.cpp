class Solution {
public:
    bool dfs(
        int src, 
        int destination, 
        vector<vector<int>>& adj, 
        vector<int>& visited
    ){
        visited[src] =1;
        if(src == destination) return true;

        for(auto &v: adj[src]){
            if(!visited[v]){
                bool ans = dfs(v, destination, adj, visited);
                if(ans) return true;
            }

            else if(v == destination) return true;
        }

        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<vector<int>>adj(numCourses);

        for(auto &edge: prerequisites){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        vector<bool>ans(queries.size());

        for(int query=0; query<queries.size(); query++){
            int source = queries[query][0];
            int destination = queries[query][1];

            vector<int>visited(numCourses, 0);
            ans[query] = dfs(source, destination, adj, visited);
        }

        return ans;
    }
};