/**
 * @brief 운동
 * 일단 최단경로를 다 구하고 cycle 확인을 위해 자기 자신으로 가는 경로가 있는 지 확인한다.
 * [i][i] 를 0으로 하고 업뎃했다가 틀렸는데 생략하니까 맞았다
 * 왠지 모르겠음 ㅎ; 암튼 플로이드 와샬이다
 * 다익스트라로도 풀 수 있다고 한다. 근데 나 다익스트라 다 까먹음;
 * @link https://www.acmicpc.net/problem/1956
 *
 * @date 2023-10-08
 */

#include <cmath>
#include <iostream>

using namespace std;

int weights[401][401];
const int INF = 1e9;

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  int V, E;
  cin >> V >> E;
  for (int i = 1; i <= V; ++i) {
    for (int j = 1; j <= V; ++j) {
      weights[i][j] = INF;
    }
  }

  while (E > 0) {
    --E;
    int key, value, weight;
    cin >> key >> value >> weight;
    weights[key][value] = weight;
  }

  for (int i = 1; i <= V; ++i) {
    for (int j = 1; j <= V; ++j) {
      for (int k = 1; k <= V; ++k) {
        // i ~ k + k ~ j 와 i ~ j 중 가장 짧은 길을 찾는다.
        weights[i][j] = min(weights[i][j], weights[i][k] + weights[k][j]);
      }
    }
  }

  int min_cycle = INF;
  for (int i = 1; i <= V; ++i) {
    min_cycle = min(min_cycle, weights[i][i]);
  }
  if (min_cycle == INF) {
    min_cycle = -1;
  }
  cout << min_cycle;
}
