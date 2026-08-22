class Solution {
public:
    void dfs(
        int src, 
        vector<vector<int>>& forward_nbrs, 
        vector<vector<int>>& backward_nbrs,
        vector<int>& visited,
        int& ans
    ){
        visited[src] =1;
        for(auto v: forward_nbrs[src]){
            if(!visited[v]){
                dfs(v, forward_nbrs, backward_nbrs, visited, ans);
                ans+=1;
            }
        }


        for(auto v: backward_nbrs[src]){
            if(!visited[v]){
                dfs(v, forward_nbrs, backward_nbrs, visited, ans);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> forward_nbrs(n);
        vector<vector<int>> backward_nbrs(n);
        vector<int>visited(n, 0);
        int ans =0;

        for(auto conn: connections){
            int u = conn[0];
            int v = conn[1];

            forward_nbrs[u].push_back(v);
            backward_nbrs[v].push_back(u);
        }

        dfs(0, forward_nbrs, backward_nbrs, visited, ans);

        return ans;
    }
};


// 0->[1]
// 1->[3]
// 2->[3]
// 3->[]
// 4->[0,5]
// 5->[]


// 0->[4]
// 1->[0]
// 2->[]
// 3->[1,2]
// 4->[]
// 5->[4]

// // 0  1  2  3  4  5
// //[1, 1, 1, 1, 0, 0]

// 0->1->3
// // 3 does not have any forward connection so we went backward
// 3->2