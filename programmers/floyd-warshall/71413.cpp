/**
 * @brief 합승 택시 요금
 * 플로이드 와샬 알고리즘을 이용해서 풀었다. 생전 처음 들어봐서 구글링해서 풀었음..
 * 장점: 코드가 깔끔함. 모든 경로의 최단 거리 구할 때 유용함
 * 단점: O(v^3) 임.. 이 문제는 간선 최대 개수가 299 개 였으므로 괜찮았지만 수가 커지면 다른 알고리즘을 사용해야 한다. ex) 다익스트라
 *
 * @link https://school.programmers.co.kr/learn/courses/30/lessons/72413
 * @date 2023-09-28
 */

#include <iostream>
#include <vector>

using namespace std;

const int INF = 30000000;

// n -> 지점의 개수, s-> 출발
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
  int d[201][201];

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i == j) {
        d[j][i] = 0;
      } else {
        d[j][i] = INF;
      }
    }
  }

  for (auto it = fares.begin(); it != fares.end(); ++it) {
    vector<int> &v = *it;
    d[v[0]][v[1]] = v[2];
    d[v[1]][v[0]] = v[2];
  }

  // 최단거리 업데이트
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        d[j][i] = d[i][j];
      }
    }
  }

  int answer = INF;
  for (int i = 1; i <= n; ++i) {
    answer = min(answer, d[i][a] + d[i][b] + d[i][s]);
  }
  return answer;
}

int main(void) {
  int n = 6;
  int s = 4;
  int a = 6;
  int b = 2;
  vector<vector<int>> fares = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2},
                               {3, 1, 41}, {5, 1, 24}, {4, 6, 50},
                               {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};
  int answer = solution(n, s, a, b, fares); // 82
  cout << answer << endl;
  return 0;
}
