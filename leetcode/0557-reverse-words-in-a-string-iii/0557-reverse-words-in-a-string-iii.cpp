class Solution {
public:
    string reverseWords(string s) {
        auto it = s.begin();
        int pos = 0;
        int prev = 0;

        while (pos != string::npos) {
            prev = pos;
            pos = s.find(' ', pos);
            reverse(it + prev, (pos != string::npos) ? it + pos++ : s.end());
        }

        return s;
    }
};