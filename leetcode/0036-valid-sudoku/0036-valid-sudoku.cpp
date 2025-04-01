class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            //vertical, horizonal, square
            bool v[9] = {};
            bool h[9] = {};
            bool s[9] = {};

            for (int j = 0; j < 9 ; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - 1 - '0';
                    if (v[num]) {
                        return false;
                    } else { 
                        v[num] = true;
                    }
                }
                if (board[j][i] != '.') {
                    int num = board[j][i] - 1 - '0';
                    if (h[num]) {
                        return false;
                    } else { 
                        h[num] = true;
                    }
                }
                int row = (i / 3) * 3 + j / 3;
                int col = (i % 3) * 3  + j % 3;
                if (board[row][col] != '.') {
                    int num = board[row][col] - 1 - '0';
                    if (s[num]) {
                        return false;
                    } else { 
                        s[num] = true;
                    }
                }

            }
        }
        return true;
    }
};