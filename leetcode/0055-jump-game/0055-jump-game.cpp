class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0; // 가장 먼 위치.

        for (int i = 0; i < n; ++i) {
            if (i > maxReach) {
                return false; // 현재 위치에 도달할 수 없음.
            }
            maxReach = max(maxReach, i + nums[i]);
            // 현재 인덱스에서 갈 수 있는 가장 먼 곳을 업데이트.
            // 실제로 실행해보지 않아도 최대 거리를 구할 수 있다.

            if (maxReach >= n - 1) {
                return true;
            }
        }
        
        return false;
    }
};