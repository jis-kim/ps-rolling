class Solution {
private:
    struct Info {
        int time;
        int x;
        int y;
        int parity; // 이동 횟수의 홀/짝 (0: 짝수, 1: 홀수)

        bool operator>(const Info& other) const {
            return time > other.time;
        }
    };

public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();

        // 4방향 이동
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        // 도착 시간 저장 배열: [x][y][parity]
        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
        dist[0][0][0] = 0;

        // 우선순위 큐 (도착 시간 오름차순)
        priority_queue<Info, vector<Info>, greater<>> pq;
        pq.push({0, 0, 0, 0}); // (time, x, y, 이동횟수 짝/홀)

        while (!pq.empty()) {
            auto [time, x, y, parity] = pq.top();
            pq.pop();

            // 도착지 도달
            if (x == n - 1 && y == m - 1)
                return time;

            // 이미 더 빠른 경로가 있으면 스킵
            if (time > dist[x][y][parity])
                continue;

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                int departTime = max(time, moveTime[nx][ny]);
                int nextParity = 1 - parity;
                int arriveTime = departTime + 1;
                if (nextParity == 0) ++arriveTime; // 도착이 짝수번째면 +1초 추가

                if (arriveTime < dist[nx][ny][nextParity]) {
                    dist[nx][ny][nextParity] = arriveTime;
                    pq.push({arriveTime, nx, ny, nextParity});
                }
            }
        }

        return -1; // 도달 불가능한 경우
    }
};
