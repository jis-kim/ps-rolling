class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        bool dp[300] = {}; // false
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        dp[0] = true; 

        // 0 ~ i(i미포함)
        for (int i = 1; i <= s.size(); ++i) {
            cout<< "i : " << i  << endl;
            for (int j = 0; j <= i; ++j) {
                // i -> 0 ~ i까지 wordDict의 구성임. (i포함)
                // 0 ~ j, j ~ i
                // substr의 두번째 인자는 length
                if (dp[j] && st.find(s.substr(j, i - j)) != st.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};