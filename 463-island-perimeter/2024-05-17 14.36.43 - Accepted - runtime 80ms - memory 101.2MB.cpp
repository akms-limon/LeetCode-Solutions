class Solution {
    int n, m, cnt = 0, sr, sc;
public:
    void dfs(int sr, int sc, vector<vector<int>> &grid) {
        if (sr < 0 || sc < 0 || sr >= n || sc >= m || grid[sr][sc] == 0) {
            cnt++;
            return;
        }
        if (grid[sr][sc] == 2) return;
        grid[sr][sc] = 2;
        dfs(sr + 1, sc, grid);
        dfs(sr - 1, sc, grid);
        dfs(sr, sc + 1, grid);
        dfs(sr, sc - 1, grid);
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    sr = i; sc = j;
                }
            }
        }
        dfs(sr, sc, grid);
        return cnt;
    }
};