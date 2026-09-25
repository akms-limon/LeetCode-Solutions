class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9, m = 9;
        bool bl = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    int cnt = 0;
                    for (int k = 0; k < 9; k++) {
                        if (board[k][j] == board[i][j]) cnt++;
                        if (board[i][k] == board[i][j]) cnt++;
                    }
                    if (cnt > 2) bl = false;
                    int p = (i / 3) * 3, q = (j / 3) * 3;
                    cnt = 0;
                    for (int l = p; l < p + 3; l++) {
                        for (int r = q; r < q + 3; r++) {
                            if (board[l][r] == board[i][j]) {
                                cnt++;
                            }
                        }
                    }
                    if (cnt >= 2) bl = false;
                }
            }
        }
        return bl;
    }
};