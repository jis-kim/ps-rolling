class Solution {
public:
    int romanToInt(string s) {
        string romans = "IVXLCDM";
         // 0, 2, 4
        int digits[] = {1, 5, 10, 50, 100, 500, 1000};
        int prev = -1;
        int result = 0;
        for (char c: s) {
            int index = romans.find(c);
            result += digits[index];
            if(prev == -1) {
                if (index == 0 || index == 2 || index == 4) prev = index;
            } else {
                if ((index > 0 && index <= 2 && prev == 0) || (index > 2 && index <= 4 && prev == 2) || (index > 4 && prev == 4)) {
                    result -= (digits[prev] * 2);
                }
                    prev = -1;
            }
        }
        return result;
    }
};