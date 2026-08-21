class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        queue<pair<int,int>>q;
        vector<vector<int>>visited(m, vector<int>(n,0));

        int originalcolor = image[sr][sc];
        if(originalcolor == color) return image;

        image[sr][sc] = color;
        visited[sr][sc] =1;
        q.push({sr,sc});

        while(!q.empty()){
            pair<int,int>curr = q.front();
            q.pop();

            int r = curr.first;
            int c = curr.second;

            vector<int> dr = {-1,1,0,0};
            vector<int> dc = {0,0,-1,1};

            for(int i=0; i<4; i++){
                int nr = r+dr[i];
                int nc = c+dc[i];

                if(nr<0 || nc<0 || nr >=m || nc >=n) continue;
                if(image[nr][nc] != originalcolor) continue;
                if(visited[nr][nc] == 1) continue;

                image[nr][nc] = color;
                q.push({nr,nc});
            }
        }

        return image;
    }
};