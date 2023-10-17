/**
 * @brief 파티
 * 처음에는 2 * N번의 다익스트라로 풀었음
 * 근데 천재 풀이를 발견해서 바꿈
 * i -> X , X -> i 의 최단 경로가 필요한데 전자를 구하기 위해 역방향의 graph 도 따로 저장함
 * 그러면 다익스트라 2번 돌려서 모든 케이스 수집 가능 개 이 득
 * @link https://www.acmicpc.net/problem/1238
 *
 * @date 2023-10-17
 */

#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> _P;

int N, M, X;
vector<pair<int, int>> graph[2][1001];
const int INF = 1e9;
int dist[2][1001];

struct comp {
  bool operator()(_P a, _P b) { return a.first > b.first; }
};

void dijkstra(int c) {
  priority_queue<_P, vector<_P>, comp> q;
  for (int i = 1; i <= N; ++i) {
    dist[c][i] = INF;
  }
  q.emplace(0, X);
  dist[c][X] = 0;

  while (q.empty() == false) {
    int cost = q.top().first;
    int x = q.top().second;
    q.pop();

    for (auto it = graph[c][x].begin(); it != graph[c][x].end(); ++it) {
      if (dist[c][it->first] > cost + it->second) {
        dist[c][it->first] = cost + it->second;
        q.emplace(dist[c][it->first], it->first);
      }
    }
  }
}

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> M >> X;
  for (int i = 0; i < M; ++i) {
    int s, e, t;
    cin >> s >> e >> t;
    graph[0][s].emplace_back(e, t);
    graph[1][e].emplace_back(s, t);
  }

  dijkstra(1);
  dijkstra(0);

  int max_dist = 0;
  for (int i = 1; i <= N; ++i) {
    max_dist = max(max_dist, dist[0][i] + dist[1][i]);
  }
  cout << max_dist;
}
