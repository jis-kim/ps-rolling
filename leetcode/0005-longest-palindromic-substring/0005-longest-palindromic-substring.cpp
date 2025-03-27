class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
    
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0, len = 1;

        // 가장 긴 팰린드롬 찾기
        // 굉장히 전형적인 문제지만 기억이 안난다. 반으로 쪼개서 어떻게 했던 것 같은데..
        // 길이가 1인 팰린드롬 처리
        for (int i = 0; i < n; i++) dp[i][i] = true;

        // 길이가 2인 팰린드롬 처리
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                len = 2;
            }
        }

        // 길이가 3 이상인 팰린드롬 찾기
        for (int l = 3; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    len = l;
                }
            }
        }
        // pos, count
        return s.substr(start, len);
    }
};