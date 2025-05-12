class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        // 순열 중 짝수인 것을 리턴함. (끝 수가 짝수)
        set<int> evens;
        int len = digits.size();
        for (int i = 0; i < len; ++i) {
            if (digits[i] == 0) continue;
            for (int j = 0; j < len; ++j) {
                if (j == i) continue;
                for (int k = 0; k < len; ++k) {
                    if (j == k || i == k) continue;
                    if (digits[k] % 2 != 0) continue;
                    evens.insert(digits[i] * 100 + digits[j] * 10 + digits[k]);
                }
            }
        }
       return vector<int>(evens.begin(), evens.end());
    }
};