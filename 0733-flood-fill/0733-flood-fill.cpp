class Solution {
public:
    void dfs(
        int m,
        int n, 
        int sr,
        int sc,
        int originalColor,
        int color,
        vector<vector<int>>& visited,
        vector<vector<int>>& image
    ){
        if(sr <0 || sr >=m || sc<0 || sc>=n) return;
        if(image[sr][sc]!=originalColor) return;

        visited[sr][sc] =1;
        image[sr][sc] = color;

        dfs(m, n, sr-1, sc, originalColor, color, visited, image);
        dfs(m, n, sr+1, sc, originalColor, color, visited, image);
        dfs(m, n, sr, sc-1, originalColor, color, visited, image);
        dfs(m, n, sr, sc+1, originalColor, color, visited, image);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        vector<vector<int>>visited(m, vector<int>(n, 0));
        int originalColor = image[sr][sc];
        if(originalColor == color) return image;

        dfs(m, n, sr, sc, originalColor, color, visited, image);

        return image;
    }
};