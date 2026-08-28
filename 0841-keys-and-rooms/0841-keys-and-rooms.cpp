class Solution {
public:
    void dfs(
        int src, 
        vector<vector<int>>& rooms, 
        vector<int>& visited
    ){
        visited[src] =1;
        for(auto room: rooms[src]){
            if(!visited[room]){
                dfs(room, rooms, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>visited(n, 0);
        dfs(0, rooms, visited);

        for(int i=0;i<n;i++){
            if(visited[i] == 0) return false;
        }

        return true;
    }
};