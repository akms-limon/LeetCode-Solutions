class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = x, r = x + k - 1; i < r; i++, r--) {
          for (int j = y; j < y + k; j++) {
            swap(grid[i][j], grid[r][j]);
          }
        }
      return grid;
    }
};