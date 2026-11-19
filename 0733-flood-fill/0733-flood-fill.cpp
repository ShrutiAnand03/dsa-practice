class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int originalcolor = image[sr][sc];
        if(originalcolor == color)  return image;

        vector<vector<int>>visited(m, vector<int>(n, 0));
        queue<pair<int,int>>q;


        q. push({sr, sc});  
        visited[sr][sc] =1;
        image[sr][sc] = color;

        vector<int>drow = {-1, 1, 0, 0};
        vector<int>dcol = {0, 0, 1, -1};


        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            q.pop(); 


            for(int i=0; i<4; i++){   // (0, 1), (1,0)
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(
                    nrow >=0 && nrow <m && ncol >=0 && ncol <n
                    && visited[nrow][ncol]!=1
                    && image[nrow][ncol] == originalcolor
                ){
                    q.push({nrow, ncol});
                    visited[nrow][ncol] =1;
                    image[nrow][ncol] =color;
                }
            }
        }

        return image;
    }
};