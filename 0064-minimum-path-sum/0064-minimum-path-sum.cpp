class Solution {
public:
    int solve(
        int row, 
        int col, 
        vector<vector<int>>& grid,
        vector<vector<int>>& dp
    ){
        if(row == 0 && col == 0) return grid[row][col];
        if(row < 0 || col < 0) return INT_MAX;

        if(dp[row][col]!=-1) return dp[row][col];

        int up = solve(row-1, col, grid, dp);
        if(up!=INT_MAX) up+=grid[row][col];

        int left = solve(row, col-1, grid, dp);
        if(left!=INT_MAX) left+=grid[row][col];

        return dp[row][col] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, grid, dp);
    }
};