/**
 * @brief 녹색 옷 입은 애가 젤다지?
 *
 * bfs 로 풀어도 풀리는 문제지만 다익스트라가 정설.
 * preority queue 를 사용할 때 가장 큰 값이 우선순위를 가짐에 주의해야 함.
 * 처음에 < 로 comp 선언했다가 시간초과뜸..
 * @link https://www.acmicpc.net/problem/4485
 *
 * @date 2023-10-13
 */

#include <cmath>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, pair<int, int>> _value;
struct comp {
  // preority queue 는 값이 클 수록 우선순위를 가지므로 greater 여야 가장 작은 게 top 이 된다.
  bool operator()(_value a, _value b) { return a.first > b.first; };
};
int weight[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int dist[126][126];
const int INF = 1e9;

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  int N = -1;
  int cnt = 0;
  while (N != 0) {
    cin >> N;
    if (N == 0) {
      return 0;
    }

    int map[126][126] = {0};
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        cin >> map[i][j];
        dist[i][j] = INF;
      }
    }

    priority_queue<_value, vector<_value>, comp> q;
    q.emplace(map[0][0], make_pair(0, 0));
    dist[0][0] = map[0][0];

    while (q.empty() == false) {
      int cost = q.top().first;
      auto ax = q.top().second;
      q.pop();

      int min_cost = INF;
      for (int j = 0; j < 4; ++j) {
        int x = ax.first + weight[j][0];
        int y = ax.second + weight[j][1];
        if (x >= 0 && y >= 0 && x < N && y < N &&
            dist[x][y] > cost + map[x][y]) {
          dist[x][y] = cost + map[x][y];
          // 선택지 중 가장 작은 값을 고르려면 여기가 dist 여야 함;
          q.emplace(dist[x][y], make_pair(x, y));
        }
      }
    }
    cout << "Problem " << ++cnt << ": " << dist[N - 1][N - 1] << "\n";
  }
}
