class Solution {
public:
    int rob(vector<int>& nums) {
        // adjacent house - 인접한 집
        // police에게 알리지 않고 털 수 있는 가장 많은 돈.ㅋㅋ
        int dp[100];

        dp[0] = nums[0];
        if (nums.size() >= 2) {
            dp[1] = max(nums[0], nums[1]);
        }
        /**
        i번째 집까지 고려했을 때 훔칠 수 있는 최대 금액은 얼마인가?"라는 관점으로 접근해보세요.
        i번째 집을 털면, i-1번째 집은 털 수 없으므로 i-2번째 집까지의 최대 금액에 nums[i]를 더합니다.
        i번째 집을 털지 않으면, 최대 금액은 i-1번째 집까지의 최대 금액과 같습니다.
        */

        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[nums.size() - 1];
    }
};