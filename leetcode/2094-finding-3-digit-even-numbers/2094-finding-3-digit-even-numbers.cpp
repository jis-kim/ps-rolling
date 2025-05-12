class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        bool seen[1000] = {false};
        vector<int> result;

        int n = digits.size();
        for (int i = 0; i < n; ++i) {
            if (digits[i] == 0) continue;  // 첫 자리는 0이면 안 됨
            for (int j = 0; j < n; ++j) {
                if (j == i) continue;
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) continue;
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (num % 2 == 0 && !seen[num]) {
                        seen[num] = true;
                        result.push_back(num);
                    }
                }
            }
        }

        sort(result.begin(), result.end());  // 정렬 필요 시
        return result;
    }
};