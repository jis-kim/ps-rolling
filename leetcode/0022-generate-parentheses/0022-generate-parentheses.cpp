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
        selectPat("(", n - 1, n);
        return res;
    }
};