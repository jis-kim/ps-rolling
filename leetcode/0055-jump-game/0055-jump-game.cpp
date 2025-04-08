class Solution {
private:
    bool visited[10000];

    // reverse side brute force
    bool findNextHop(vector<int>& nums, int index) {
        // 현재 노드가 마지막 노드이거나 그보다 크면 끝에 도달한 것이다.
        if (index >= nums.size() - 1) {
            return true;
        }
        if (nums[index] == 0 || visited[index] == true) {
            return false;
        }
        visited[index] = true;
        int range = nums[index];

        // 현재 노드가 0이 아닐 때까지 진행할 수 있다.
        // true가 나올때까지 index + 1 ~ index + range를 역순으로 돈다.
        for (;range > 0; --range) {
            if(findNextHop(nums, index + range)) { // 이전 노드들이 다 true이면 true이다.
                return true;
            }
        }
        // 없으면 이 노드는 망했다.
        return false;
    }

public:
    bool canJump(vector<int>& nums) {
        return findNextHop(nums, 0);
    }
};