class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // 0이면 가로세로 죄다 0이됨 . matrix자체에다 하여라!
        int n = matrix.size();
        int m = matrix[0].size();

        unordered_set<int> row;
        unordered_set<int> col;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for (auto it = row.begin(); it != row.end(); ++it) {
            int r = *it;
            for (int i = 0; i < m; ++i) {
                matrix[r][i] = 0;
            }
        }
        for (auto it = col.begin(); it != col.end(); ++it) {
            int c = *it;
            for (int i = 0; i < n; ++i) {
                matrix[i][c] = 0;
            }
        }
    }
};