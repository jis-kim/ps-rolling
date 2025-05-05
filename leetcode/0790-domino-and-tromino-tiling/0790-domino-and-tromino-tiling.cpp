class Solution {
public:
    int numTilings(int n) {
        long long dp[1001] = {};
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for (int i = 4; i <= n; ++i) {
            dp[i] = (2 * dp[i - 1] + dp[i - 3]) % (1000000000  + 7);
        }
        // return modulo 10^9 + 7   
        return dp[n];
    }
};