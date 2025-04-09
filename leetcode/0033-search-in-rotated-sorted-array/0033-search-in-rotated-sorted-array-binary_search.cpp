class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0; 
        int right = nums.size() - 1;

        while(left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[left] <= nums[mid]){
                // 왼쪽 숫자가 작으면, 왼쪽이 정렬된 것이다.
                if (nums[left] <= target && nums[mid] > target) {
                    right = mid - 1; // mid를 포함하면 안됨에 주의
                } else {
                    left = mid + 1;
                }
            } else {
                // 오른쪽이 정렬됨
                if (nums[mid] < target && nums[right] >= target) {
                    // 정렬범위에서 찾는다.
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};