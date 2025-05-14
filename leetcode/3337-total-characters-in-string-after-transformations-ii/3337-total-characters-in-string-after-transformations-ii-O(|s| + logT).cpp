class Solution {
using Matrix = array<array<int, 26>, 26>;
const int mod = 1e9 + 7;

private: 
    Matrix multiplyMatrix(Matrix &a, Matrix &b) {
        Matrix c{};

        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b.size(); ++j) {
                for (int k = 0; k < a.size(); ++k) {
                    c[i][j] = ((c[i][j])%mod + (1LL * a[i][k] * b[k][j])%mod) % mod;
                }
            }
        }

        return c;
    }

public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        // 한 transformation에서 매 s가 다음 룰에 의해 바뀜.
        // s[i]를 다음 nums[s[i] - 'a']만큼의 연속 문자열로 대체하시오.
        // s[i]가 'a'고 nums[0]이 3이면, 'a'는 다음 3개의 연속 문자열인 bcd가 됨.
        // 이 transformation은 z을 초과하면 wrap-around함. (a로 돌아감)

        // length of the string을 구하쇼.
        Matrix mat{}; // 각 알파벳별 변환 수
        // cycle one
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j <= nums[i]; ++j) {
                if (i + j < 26) {
                    ++mat[i][i + j];
                } else {
                    ++mat[i][(i + j) % 26];
                }
            }
        }

        Matrix freq{}; // 등장 빈도
        for (char c: s) {
            freq[c - 'a'][c - 'a']++;
        }

        // matrix 행렬을 t번 곱함.
        // 행렬곱 :c의 i, j는 a의 i행 요소 * b의 j열 요소를 곱하여 모두 더한 것.
        // j->k: j가 k를 만드는 수
        // k->i: k가 i.
        // jk * ki = j -> i . 모든 k를 고려해야 되니까 행렬곱인 것이다.

        Matrix origin{}; 
        for (int i = 0; i < 26; ++i) {
            ++origin[i][i];
        }
        // 비트연산으로 t계산 
        while (t > 0) {
            if (t & 1) {
                // 2의 거듭제곱이면
                origin = multiplyMatrix(origin, mat); // freq를 변형
            }
            mat = multiplyMatrix(mat, mat); // 곱할넘을 변형.
            t >>= 1;
        }

        freq = multiplyMatrix(freq, origin);

        int count = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                count = (count + freq[i][j]) % mod;
            }
        }

        return count;
    }
};