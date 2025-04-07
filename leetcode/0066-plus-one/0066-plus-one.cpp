class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool up = true;

        for (int i = digits.size() - 1; i >= 0; --i) {
            int plusOne = up ? digits[i] + 1 : digits[i];
            digits[i] = plusOne % 10;
            if (plusOne < 10) {
                up = false;
                break;
            }
            up = true;
        }
        if (up) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};