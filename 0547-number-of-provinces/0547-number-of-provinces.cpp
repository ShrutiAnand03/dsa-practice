class Solution {
public:
    void dfs(
        int src, 
        vector<vector<int>>& isConnected, 
        vector<int>& visited
    ){
        visited[src] =1;

        for(int i=0; i<isConnected[src].size(); i++){
            if(isConnected[src][i] == 1 && !visited[i]){
                dfs(i, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>visited(n);
        int noOfProviences = 0;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, isConnected, visited);
                noOfProviences++;
            }
        }

        return noOfProviences;
    }
};
