class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        // 5의 거듭제곱으로 중복해서 나눔
        for (int i = 5; n / i > 0; i *= 5) {
            count += n / i;
        }
        return count;
    }
};