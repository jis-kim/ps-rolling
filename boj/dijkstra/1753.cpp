/**
 * @brief 최단경로
 * 그냥... 다익스트라인데 난 그냥 다익스트라도 안보고는 못푸는 구나 느꼈다.
 * 다익스트라 연습을 좀 더 해야겠다.
 * @link https://www.acmicpc.net/problem/1753
 *
 * @date 2023-11-08
 */

#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int V, E, K;
const int INF = 1e9;

int dist[200001];
vector<pair<int, int>> graph[200001];

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  cin >> V >> E >> K;
  for (int i = 0; i < E; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].emplace_back(v, w);
  }

  for (int i = 1; i <= V; ++i) {
    dist[i] = INF;
  }

  dist[K] = 0;
  pq.emplace(0, K);

  while (pq.empty() == false) {
    int cost = pq.top().first;
    int node = pq.top().second;

    pq.pop();

    for (auto &edge : graph[node]) {
      int next = edge.first;
      int next_cost = edge.second + cost; // 현재 ~ next 까지의 거리

      if (dist[next] > next_cost) {
        dist[next] = next_cost;
        pq.emplace(next_cost, next);
      }
    }
  }

  for (int i = 1; i <= V; ++i) {
    if (dist[i] == INF)
      cout << "INF\n";
    else
      cout << dist[i] << '\n';
  }
}
