class Solution {
private:
    int left;
    int right;
    vector<string> res;

    void selectPat( string s) {
        if (left == 0 && right == 0) {
            res.push_back(s);
            return;
        }
        if (left > 0) {
            --left;
            selectPat(s + "(");
            ++left;
        }
        if (right > left && right > 0){
            --right;
            selectPat(s + ")");
            ++right;
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        left = n - 1;
        right = n;

        selectPat("(");

        return res;
    }
};