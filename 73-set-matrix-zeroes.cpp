class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int col0 = -1;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (matrix[row][col] == 0) {
                    matrix[row][0] = 0;
                    if (col == 0) col0 = 0;
                    else matrix[0][col] = 0;
                }
            }
        }
        for (int row = 1; row < n; row++) {
            if (matrix[row][0] == 0) {
                for (int col = 0; col < m; col++) {
                    matrix[row][col] = 0;
                }
            }
        }
        for (int col = 1; col < m; col++) {
            if (matrix[0][col] == 0) {
                for (int row = 0; row < n; row++) {
                    matrix[row][col] = 0;
                }
            }
        }
        if (matrix[0][0] == 0) {
            for (int col = 0; col < m; col++) {
                matrix[0][col] = 0;
            }
        }
        if (col0 == 0) {
            for (int row = 0; row < n; row++) {
                matrix[row][0] = 0;
            }
        }
    }
};