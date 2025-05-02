class Solution {
private:
    void fillRange(string& dominoes, int left, int right) {
        // right ~ left의 구간을 //\\형태로 채웁니다.
        int count = left - right + 1;
        int half = right + (count / 2);
        // cout << "left : " << left << ", right: " << right << endl;
        // cout << "count : " << count << ", half: " << half << endl;

        for (int i = right; i <= left; ++i) {
            if (i < half) {
                dominoes[i] = 'R';
            } else if (i > half) {
                dominoes[i] = 'L';
            } else {
                if (count % 2 == 0) {
                    dominoes[i] = 'L';
                } else {
                    dominoes[i] = '.';
                }
            }
        }
    }

public:
    string pushDominoes(string dominoes) {
        int len = dominoes.length();

        int left = -1, right = -1;

        for (int i = 0; i < len; ++i) {
            if (dominoes[i] == 'L') {
                if (right == -1) {
                    // fill
                    // left + 1 ~ i까지 채운다.
                    for (int j = left + 1; j < i; ++j) {
                        dominoes[j] = 'L';
                    }
                } else { // right가 있음
                   fillRange(dominoes, i, right);
                   right = -1;
                }
                left = i;
            } else if (dominoes[i] == 'R') {
                if (right != -1) {
                    for (int j = right + 1; j < i; ++j) {
                        dominoes[j] = 'R';
                    }
                }
                right = i;
            }
        }
        if (right != -1) {
            for (int i = right; i < len; ++i) {
                dominoes[i] = 'R';
            }
        }

        return dominoes;

    }
};