class Solution {
public:
    int lengthOfLastWord(string s) {
        // length of the last word
        int end = s.find_last_not_of(' ');
        int start = s.find_last_of(' ', end);

        return end - start;
    }
};