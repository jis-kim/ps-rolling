class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        // 0 2 1 5 3 4
        vector<int> ans(nums);

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i) {
                ans[i] = nums[nums[i]];
            }
        }

        return ans;
    }
};