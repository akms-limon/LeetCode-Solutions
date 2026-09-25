class Solution {
    int m, n, curr, col;
public:
    void dfs(vector<vector<int>>& image, int sr, int sc) {
        if (sr < 0 || sc < 0 || sr >= m || sc >= n || image[sr][sc] != curr) {
            return;
        }
        image[sr][sc] = col;
        dfs(image, sr + 1, sc);
        dfs(image, sr - 1, sc);
        dfs(image, sr, sc - 1);
        dfs(image, sr, sc + 1);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        curr = image[sr][sc];
        col = color;
        if (col == curr) return image;
        dfs(image, sr, sc);
        return image;
    }
 };