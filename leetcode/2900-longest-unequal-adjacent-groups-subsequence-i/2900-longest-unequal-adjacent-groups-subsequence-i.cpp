class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        // longest alternating subsequence from words.

        int prev = -1;
        vector<string> sub;
        for (int i = 0; i < groups.size(); ++i) {
            if (prev != groups[i]) {
                sub.emplace_back(words[i]);
                prev = groups[i];
            }
        }
        return sub;
    }
};