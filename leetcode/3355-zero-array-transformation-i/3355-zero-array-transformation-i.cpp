class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int len = nums.size(); // 0 ~ len - 1;
        vector<int> diff(len, 0);

        // 차분 배열 활용. 범위 시작점에 +, (끝점 +1)에 -표시한다.
        // +시점부터 +만큼 누적, -부터는 -누적함. -> end ~ 나머지는 0이 됨.
        // 이걸 여러번 반복해도 똑같은 원리이므로 최종 계산값 생성이 가능하다.
        for (vector<int>& q: queries) {
            int s = q[0];
            int e = q[1];
            diff[s]++;
            if (e < len - 1) {
                diff[e + 1]--;
            }
        }

        int cur = 0;
        for (int i = 0; i < len; ++i) {
            cur += diff[i];
            if (cur < nums[i]) return false;
        }

        return true;
    }
};