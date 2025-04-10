class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int alpha[128] = {}; // ascii
        for (int i = 0; i < 128; ++i) {
            alpha[i] = -1;
        }
        int start = 0;
        int maxLen = 0;
        int strLen = s.length();
        for (int i = 0; i < strLen; ++i) {
            if (alpha[s[i]] != -1) {
                maxLen = max(maxLen, i - start); // 현재글자 이전까지의 길이를 저장
                // abb -> b ab
                // ba -> b
                // cout << "start: " << start<< ", end: " << i << ", maxLen: " << maxLen<<endl;
                // cout << s.substr(start, i + 1) << endl;
                start = max(start, alpha[s[i]] + 1); // 앞글자를 제외
            } 
            alpha[s[i]] = i;
        }
        // start가 움직이지 않았을 경우, 겹친 숫자가 나오지 않았을 경우 start는 0이다.
        cout << "start: " << start<< ", end: " << strLen << ", maxLen: " << maxLen<<endl;

        maxLen = max(maxLen, strLen - start);

        return maxLen;
    }
};