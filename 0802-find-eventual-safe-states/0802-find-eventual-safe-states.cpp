class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>outdegree(n, 0);
        queue<int>q;
        vector<int>ans;

        // calculate the outdegree of all the nodes
        // push only the terminal nodes in the queue at the start
        // now we have to go backward from the terminal node so we must create a backward adj list

        // initialisation
        for(int i=0; i<n; i++){
            for(auto &v: graph[i]){
                outdegree[i]++;
            }
        }

        // creating the backward list
        vector<vector<int>> backward_list(n);
        for(int i=0; i<n; i++){
            for(auto &v: graph[i]){
                backward_list[v].push_back(i);
            }
        }

        //pushing those elements in the queue which has the outdegree as 0
        for(int i=0; i<n; i++){
            if(outdegree[i] == 0){
                q.push(i);
            }
        }

        for(auto &v: ans){
            cout<<v<<" ";
        }

        while(!q.empty()){
            int f = q.front();
            q.pop();
            ans.push_back(f);

            for(auto &v: backward_list[f]){
                outdegree[v]--;

                if(outdegree[v] ==0){
                    q.push(v);
                }
            }
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};