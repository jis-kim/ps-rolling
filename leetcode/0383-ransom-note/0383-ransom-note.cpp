class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // 각 문자의 등장 횟수를 저장
        int charCount[26] = {0};
        
        // magazine의 각 문자 빈도수 계산
        for (char c : magazine) {
            charCount[c - 'a']++;
        }
        
        for (char c : ransomNote) {
            if (--charCount[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};