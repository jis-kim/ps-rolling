class Solution {
public:
    int minTimeToReach(const vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();

        // 4방향 이동
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        // 최소 도달 시간 저장 배열
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        // 우선순위 큐: (도착 시간, x, y)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,greater<>> pq;
        pq.emplace(0, 0, 0); // (time, x, y)

        while (!pq.empty()) {
            auto [time, x, y] = pq.top();
            pq.pop();

            if (x == n - 1 && y == m - 1)
                return time;

            // 이미 더 빠른 경로가 있으면 스킵
            if (time > dist[x][y])
                continue;

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                // 출발 가능한 시간까지 기다림
                int departTime = max(time, moveTime[nx][ny]);
                int arriveTime = departTime + 1;

                if (arriveTime < dist[nx][ny]) {
                    dist[nx][ny] = arriveTime;
                    pq.emplace(arriveTime, nx, ny);
                }
            }
        }

        return -1; // 도달 불가능한 경우
    }
};