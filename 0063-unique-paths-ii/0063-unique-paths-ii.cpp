class Solution {
public:
    int solve(
        int row, 
        int col, 
        vector<vector<int>>& grid,
        vector<vector<int>>& dp
    ){
        if(row == 0 && col == 0) return 1;
        if(row < 0 || col < 0) return 0;
        if(row>=0 && col>=0 && grid[row][col] == 1) return 0;
        
        if(dp[row][col]!=-1) return dp[row][col];

        int up = solve(row-1, col, grid, dp);
        int left = solve(row, col-1, grid, dp);

        return dp[row][col]= up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));

        if(obstacleGrid[0][0] == 1) return 0;

        return solve(m-1, n-1, obstacleGrid, dp);
    }
};