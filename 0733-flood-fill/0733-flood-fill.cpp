class Solution {
public:
    void dfs(
        int sr,
        int sc,
        int m, 
        int n,
        int color,
        int original_color,
        vector<vector<int>>& visited,
        vector<vector<int>>& image
    ){
        if(sr <0 || sr >=m || sc<0 || sc>=n) return;
        if(image[sr][sc]!=original_color) return;

        visited[sr][sc] =1;
        image[sr][sc] = color;

        dfs(sr-1, sc, m, n, color, original_color, visited, image); 
        dfs(sr+1, sc, m, n, color, original_color, visited, image); 
        dfs(sr, sc-1, m, n, color, original_color, visited, image); 
        dfs(sr, sc+1, m, n, color, original_color, visited, image); 

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        vector<vector<int>>visited(m, vector<int>(n, 0));
        if(image[sr][sc] == color) return image;

        int original_color = image[sr][sc];
        dfs(
            sr, 
            sc, 
            m, 
            n, 
            color, 
            original_color, 
            visited, 
            image
        );
        return image;
    }
};