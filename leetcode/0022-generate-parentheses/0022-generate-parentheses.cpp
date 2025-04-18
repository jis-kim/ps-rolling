class Solution {
private:
    vector<string> res;

    void selectPat(string s, int left, int right) {
        if (left == 0 && right == 0) {
            res.push_back(s);
            return;
        }

        if (left > 0) {
            selectPat(s + "(", left - 1, right);
        }
        if (right > left && right > 0){
            selectPat(s + ")", left, right - 1);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> dp[9] = {};
        dp[0] = { "" };
        dp[1] = { "()" };
        dp[2] = { "(())", "()()"};

        for (int i = 3; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (const string& inside : dp[j]) {
                    for (const string& outside : dp[i - 1 - j]) {
                        dp[i].push_back("(" + inside + ")" + outside);
                    }
                }
            }
        }

        return dp[n];
    }
};