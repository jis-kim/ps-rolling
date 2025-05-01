class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        
        int n = tasks.size();
        int m = workers.size();

        // k개의 가장 작은 task를 worker에게 assign할 수 있을까?
        // 모든 k를 어떻게 try 해볼까? -> 이진 탐색        

        int left = 0, right = min(n, m);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAssignTasks(tasks, workers, pills, strength, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return right;
    }
    
private:
    // Check if it's possible to complete 'count' tasks
    bool canAssignTasks(vector<int>& tasks, vector<int>& workers, int pills, int strength, int count) {
        // We only consider the first 'count' easiest tasks
        vector<int> taskSubset(tasks.begin(), tasks.begin() + count);
        multiset<int> availableWorkers(workers.end()- count, workers.end());
        
        // count개의 어려운 거ㅅ부터..
        for (int i = count - 1; i >= 0; i--) {
            int task = taskSubset[i];
            
            auto it = availableWorkers.lower_bound(task); // task보다 큰 값
            if (it != availableWorkers.end()) {
                availableWorkers.erase(it);
                // 찾음!
                continue;
            }
            
            if (pills > 0) {
                // 약먹은 task
                auto it2 = availableWorkers.lower_bound(task - strength);
                if (it2 != availableWorkers.end()) {
                    availableWorkers.erase(it2);
                    pills--;
                    continue;
                }
            }
            
            // If we reach here, the task cannot be completed
            return false;
        }
        
        return true;
    }
};