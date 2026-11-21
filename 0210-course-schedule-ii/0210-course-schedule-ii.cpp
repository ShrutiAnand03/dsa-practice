class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>indegree(numCourses, 0);
        vector<vector<int>>adj(numCourses);
        vector<int>ans;

        // create a adj list
        for(auto& edge: prerequisites){
            int u = edge[0];
            int v = edge[1];

            adj[v].push_back(u);
        }

        // calculate the indegree
        for(int i=0; i<adj.size(); i++){
            for(auto &v: adj[i]){
                indegree[v]++;
            }
        }

        // push the vertices with indegree as 0
        queue<int>q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        // bfs
        while(!q.empty()){
            int f = q.front();
            q.pop();
            ans.push_back(f);

            for(auto &v: adj[f]){
                indegree[v]--;

                if(indegree[v] == 0) q.push(v);
            }
        }

        if(ans.size() == numCourses) return ans;
        return {};
    }
};