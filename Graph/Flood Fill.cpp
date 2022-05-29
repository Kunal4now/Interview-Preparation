class Solution {
public:
    bool valid(int x , int y, int n, int m, int trueColor, vector<vector<int>> &image, vector<vector<bool>> &vis) {
        if (x < 0 || x >= n || y < 0 || y >= m)
            return false;
        if (image[x][y] != trueColor)
            return false;
        if (vis[x][y])
            return false;
        return true;
    };
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int dx[] = {-1 , 1 , 0 , 0};
        int dy[] = {0 , 0 , -1 , 1};
        
        int n = image.size(), m = image[0].size();
        
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        queue<pair<int, int>> q;
        
        q.push({sr, sc});
        vis[sr][sc] = true;
        
        int trueColor = image[sr][sc];
        
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            image[u.first][u.second] = newColor;
            for (int i = 0; i < 4; i++) {
                int x = dx[i] + u.first;
                int y = dy[i] + u.second;
                if (valid(x, y, n, m, trueColor, image, vis)) {
                    vis[x][y] = true;
                    q.push({x, y});
                }
            }
        }
        return image;
    }
};
