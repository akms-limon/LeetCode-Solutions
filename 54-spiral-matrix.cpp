class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size() - 1, m = matrix[0].size() - 1;
        vector<int> ans;
        int i = 0, j = 0;
        while (i <= n && j <= m && matrix[i][j] != -101) {
            for (int y = j; y <= m; y++) {
                if (matrix[i][y] == -101) goto here;
                ans.push_back(matrix[i][y]);
                matrix[i][y] = -101;
            }
            for (int x = i + 1; x <= n; x++) {
                if (matrix[x][m] == -101) goto here;
                ans.push_back(matrix[x][m]);
                matrix[x][m] = -101;
            }
            for (int y = m - 1; y >= j; y--) {
                if (matrix[n][y] == -101) goto here;
                ans.push_back(matrix[n][y]);
                matrix[n][y] = -101;
            }
            for (int x = n - 1; x > i; x--) {
                if (matrix[x][j] == -101) goto here;
                ans.push_back(matrix[x][j]);
                matrix[x][j] = -101;
            }
            i++, j++, n--, m--;
        }
        here:
        return ans;
    }
};