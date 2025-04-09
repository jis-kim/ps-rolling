class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 오름차순에 중복이 없는 nums
        int first = nums.front();
        int last = nums.back();
        if (first <= target) {
           // 첫번째부터 찾는다.
           int i = 0;
           for (; i < nums.size(); ++i) {
                if (nums[i] == target) {
                    return i;
                } else if (nums[i] > target || nums[i] < first) {
                    return -1;
                }
           }
        }
        else {
            // 마지막부터 찾는다.
           int i = nums.size() - 1;
           for (; i >= 0; --i) {
                if (nums[i] == target) {
                    return i;
                } else if (nums[i] < target || nums[i] > last) {
                    return -1;
                }
            }
        }
        return -1;
    }
};