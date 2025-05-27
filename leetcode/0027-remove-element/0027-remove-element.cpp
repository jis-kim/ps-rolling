class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;

        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                --n;  // 전체 유효 길이 감소
            } else {
                ++i;
            }
        }

        return n;
    }
};