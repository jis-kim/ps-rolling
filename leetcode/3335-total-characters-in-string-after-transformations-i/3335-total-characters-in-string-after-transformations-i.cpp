class Solution {
private:
    const int mod = 1e9+7;
public:
    int lengthAfterTransformations(string s, int t) {
        // t - transformation to perform을 표현함.
        // 매 s가 다음 룰에 따라 추가됨.
        // 'z' -> "ab"
        // z아니면 다음 알파벳으로 replace.
        // 정확히 "t" 번 transformation 된 후의 길이를 리턴하시오.
        //
        // t -> max: 10^5
        // a ~ z -> 26개
        // t / 26 -> 한 사이클 도는 횟수임..
        // a가 z가 되고 ab가 될려면 26번의 transformation이 있어야 함.
        // b가 z가 되고 ab -> 25번
        // c -> 24번
        // 즉 (26 - 알파벳 + 'a') 번 순회하면 2배가 됨. (z : 1번) z는 'a' + 25임.
        // a -> 26회, b-> 25회다 이걸 어쩌몀ㄴ 좋지? 헷갈리구로...
        // 26 -> (26(2625)  25(2625))

        int nums[26] = {};
        for (char c: s) {
            nums[c - 'a']++;
        }
        
        // a~z가 t 번 순회 후 문자열 몇 개가 되는지 계산함.
        for (int i = 0; i < t; ++i) {
            int cur[26] = {};
            for (int j = 0; j < 26; ++j) {
                if (j == 25 && nums[j] > 0) { //z일때
                    cur[0] = (cur[0] + nums[j]) % mod;
                    cur[1] = (cur[1] + nums[j]) % mod;
                } else {
                    if (j < 25) cur[j + 1] = (cur[j + 1] +nums[j]) % mod;
                }
            }
            for (int j = 0; j < 26; j++) nums[j] = cur[j];
        }

        int result = 0;
        for (int n: nums) {
            result = (result + n) % mod;
        }
        return result;
    }
};