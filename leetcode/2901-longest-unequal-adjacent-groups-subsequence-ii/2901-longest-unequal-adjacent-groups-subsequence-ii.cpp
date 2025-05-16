class Solution {
private:
    bool verifyByDistance(string& s1, string& s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        int count = 0;
        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] != s2[i]) {
                if (count >= 1) return false;
                ++count;
            }
        }
        return (count == 1);
    }


public:

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        // 둘다 n길이 갖고있음.
        // hamming distance 대응되는 캐릭터가 다른만큼의..길이
        // 1. 인접한 그룹이 다름. 2. haming distance가 1만큼 다름(길이는 같은) 을 만족해야함.
        int len = words.size();
        vector<vector<int>> dp(1000); // 이어지는 인덱스 저장

        dp[0].emplace_back(0);

        for (int i = 1; i < len; ++i) {
            dp[i].emplace_back(i);
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && verifyByDistance(words[i], words[j])) {
                    // 기존 subsequence보다 길이가 길면 갱신
                    if (dp[j].size() + 1 > dp[i].size()) {
                        dp[i] = dp[j];
                        dp[i].emplace_back(i);
                    }
                }
            }
        }

        int selected = 0;
        for (int i = 1; i < len ; ++i) {
            if (dp[selected].size() < dp[i].size()) {
                selected = i;
            }
        }

        vector<int>& v = dp[selected];
        vector<string> result;
        for (auto it = v.begin(); it != v.end(); ++it) {
            result.emplace_back(words[*it]);
        }

        return result;
    }
};