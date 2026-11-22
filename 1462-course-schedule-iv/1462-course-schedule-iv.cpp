class Solution {
public:
    void dfs(
        int src, 
        vector<vector<int>>& adj, 
        vector<int>& visited
    ){
        visited[src] =1;

        for(auto &v: adj[src]){
            if(!visited[v]){
                dfs(v, adj, visited);
            }
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<vector<int>>adj(numCourses);
        vector<vector<int>>matrix;

        for(auto &edge: prerequisites){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        for(int i=0; i<numCourses; i++){
            vector<int>visited(numCourses, 0);
            dfs(i, adj, visited);
            matrix.push_back(visited);
        }

        vector<bool>ans(queries.size());

        for(int query=0; query<queries.size(); query++){
            int source = queries[query][0];
            int destination = queries[query][1];
            ans[query] = matrix[source][destination];
        }

        return ans;
    }
};