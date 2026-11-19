class Solution {
public:
    void dfs(
        int src, 
        vector<vector<int>>& isConnected, 
        vector<int>& visited
    ){
        visited[src] =1;

        for(int i=0; i<isConnected[src].size(); i++){
            if(!visited[i] && isConnected[src][i] == 1){
                dfs(i, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>visited(n, 0);

        int countprov = 0;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                countprov++;
                dfs(i, isConnected, visited);
            }
        }

        return countprov;
    }
};


