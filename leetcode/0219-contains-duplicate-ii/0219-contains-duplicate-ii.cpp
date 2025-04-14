class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // nums[i] == nums[j], abs(i - j) <= k를 만족하는 i, j
        int size = nums.size();
        unordered_set<int> s;
        for(int i = 0; i < size; ++i) {
            if (i > k) s.erase(nums[i - k - 1]); // k index 이전을 삭제
            if (s.count(nums[i])) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};