class Solution {

struct node {
    int x, y;
};

public:
    void rotate(vector<vector<int>>& matrix) {
        int i = 0, j = 0, n = matrix.size() - 1, m = n;
        while (i < n) {
            node a, b, c, d;
            j = i;
            a.x = i, a.y = j, b.x = i, b.y = m, c.x = n, c.y = m, d.x = n, d.y = j;
            for (j; j < m; j++) {
                int x = matrix[i][j];
                swap(matrix[b.x][b.y], x);
                swap(matrix[c.x][c.y], x);
                swap(matrix[d.x][d.y], x);
                swap(matrix[i][j], x);
                b.x++, c.y--, d.x--;
            }
            i++, n--, m--;
        }
    }
};