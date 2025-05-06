class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        // 0 2 1 5 3 4
        vector<int> ans(nums.length());

        for (int n : nums) {
            ans.push_back(nums[n]);
        }

        return ans;
    }
};