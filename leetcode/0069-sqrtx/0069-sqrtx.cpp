class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        int start = 0, end = x;
        int ans = 0;

        while (start <= end) {
            long long mid = start + (end - start) / 2;
            long long square = mid * mid;

            if (square == x) {
                return mid;
            } else if (square < x) {
                ans = mid;        // 일단 후보로 저장 - 작은값
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return ans;
    }
};
