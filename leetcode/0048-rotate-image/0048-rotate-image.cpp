class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 겉에서부터 돌린다.
        int n = matrix.size();
        int min = 0;
        int max = n - 1;
       
        while (min < max) {
            for (int i = 0; i < max - min; ++i) {
                // 반복횟수 (길이) : max - min
                int tmp = matrix[min][min+i];
                
                // 왼쪽 상단 <- 왼쪽 하단
                matrix[min][min+i] = matrix[max-i][min];
                
                // 왼쪽 하단 <- 오른쪽 하단
                matrix[max-i][min] = matrix[max][max-i];
                
                // 오른쪽 하단 <- 오른쪽 상단
                matrix[max][max-i] = matrix[min+i][max];
                
                // 오른쪽 상단 <- 저장한 값(원래 왼쪽 상단)
                matrix[min+i][max] = tmp;
            }
            ++min;
            --max;
        }
    }
};