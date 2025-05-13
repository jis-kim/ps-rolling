class Solution {
private:
    const int mod = 1e9+7;
public:
    int lengthAfterTransformations(string s, int t) {
        // a가 z가 되고 ab가 될려면 26번의 transformation이 있어야 함.
        // b가 z가 되고 ab -> 25번
        // c -> 24번
        // 즉 (26 - 알파벳 + 'a') 번 순회하면 2배가 됨. (z : 1번) z는 'a' + 25임.
        // a -> 26회, b-> 25회다 이걸 어쩌몀ㄴ 좋지? 헷갈리구로...
        // 26 -> (26(2625)  25(2625))


        // 순차적으로 적용되니까, b는 a에 t + 1번 순회한 결과와 똑같음.
        // c는 t+2번, d는 t+3번..
        // 그래서 z인 t + 25까지 하는거임!
        // 'a'가 i번 변환됐을 때 최종적으로 몇의 길이가 되는가? 가 중요함.
        vector<int> dp(t + 26); 

        for (int i = 0; i < 26 + t; ++i) {
            if (i < 26) {
                dp[i] = 1; // 25회까지는 z임.
            } else {
                dp[i] = (dp[i - 25] + dp[i - 26]) % mod;
                // i - 25 -> z가 아닌 문자열이 됨. (ab에서 b에 대응)
                // i - 26 -> z가 됨. ("ab"에서 a에 대응)
                // 이미 a, b가 파생된결과를 더하는거라서 26*2가 아님.
            }
        }


        int result = 0;
        for (char c: s) {
            result = (result + dp[t + c - 'a']) % mod;
        }
        return result % mod;
    }
};