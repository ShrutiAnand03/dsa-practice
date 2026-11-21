class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // so prerequisites array is basically here the edge list
        // we will apply topological sort here as a particular course depends on the other
        vector<int>indegree(numCourses, 0);
        vector<vector<int>>adj(numCourses);
        vector<int>bfs;

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


        // push the vertices in the queue whose indegree is 0
        queue<int>q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        // apply bfs
        while(!q.empty()){
            int f = q.front();
            q.pop();

            bfs.push_back(f);

            for(auto &v: adj[f]){
                indegree[v]--;

                if(indegree[v] == 0) q.push(v);
            }
        }

        return bfs.size() == numCourses;
    }
};