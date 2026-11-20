class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int shared_lines =0;
        int no_of_islands =0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(grid[i][j] == 1){
                    
                    no_of_islands++;

                    if(j+1 < n && grid[i][j+1] == 1) shared_lines++;

                    if(i+1 < m && grid[i+1][j] == 1) shared_lines++;
                }
            }
        }

        return 4*no_of_islands - 2*shared_lines;
    }
};