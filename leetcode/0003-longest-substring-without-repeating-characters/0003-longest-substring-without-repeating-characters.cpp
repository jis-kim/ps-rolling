class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int alpha[128] = {}; // ascii
        for (int i = 0; i < 128; ++i) {
            alpha[i] = -1;
        }
        int start = 0;
        int maxLen = 0;

        for (int i = 0; i < s.length(); ++i) {
            // 문자가 이미 현재 부분 문자열 내에 있는 경우, 시작점을 이동
            if (alpha[s[i]] >= start) {
                start = alpha[s[i]] + 1;
            } 
            // 현재 부분 문자열 길이 갱신
            maxLen = max(maxLen, i - start + 1);
            
            // 현재 문자의 위치 갱신
            alpha[s[i]] = i;
        }

        return maxLen;
    }
};