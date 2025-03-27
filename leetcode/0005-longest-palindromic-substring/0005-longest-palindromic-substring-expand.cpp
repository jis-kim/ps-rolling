class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";

        int start = 0, maxLen = 1;

        // 중심 확장법으로 팰린드롬 찾기
        for (int i = 0; i < n; ++i) {
            // 홀수 길이 팰린드롬 찾기 (중심이 i)
            int len1 = expandAroundCenter(s, i, i);
            // 짝수 길이 팰린드롬 찾기 (중심이 i와 i+1 사이)
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;  // 팰린드롬 시작 위치
            }
        }

        return s.substr(start, maxLen);
    }

private:
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;  // 팰린드롬의 길이
    }
};
