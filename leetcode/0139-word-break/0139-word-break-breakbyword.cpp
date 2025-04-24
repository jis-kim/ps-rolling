class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        bool dp[300] = {}; // false
        dp[0] = true; 

        // 0 ~ i(i미포함)
        for (int i = 1; i <= s.size(); ++i) {
            for (const string& w : wordDict) {
                int start = i - w.length();
                // 현재 단어가 start에 있다 가정.
                // start가 0보다 크고, start이전이 true이고, start ~ w.lendth가 w와 같으면 true.
                // 즉 1씩 증가시키는게 아니라 wordDict의 글자수로 쪼개서 본다.
                // wordDict의 가능성을 탐색하는것임. 굉장히 똑똑한 방식인듯....
                if (start >= 0 && dp[start] && s.substr(start, w.length()) == w) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};