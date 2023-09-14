/**
 * @brief 전력망을 둘로 나누기
 * 둘 로 나 눠 서 개 수 를 세 는 문 제 였 는 데 문 제 를 잘 못 봐 서 송 신 탑 번
 * 호 를 합 산 중 이 었 다.. 어 이 없 어 개 수 를 세 는 거 면 훨 씬 쉬 운 데 . .
 * vscode korean 언 제 고 침??..
 *
 * @link https://school.programmers.co.kr/learn/courses/30/lessons/86971
 *
 * @date 2023-09-15
 */

#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

// n <= 100

int solution(int n, vector<vector<int>> wires) {
  int answer = 10000;

  map<int, vector<int>> tree;
  vector<int> visited(101, 0);

  for (auto it = wires.begin(); it != wires.end(); ++it) {
    tree[(*it)[0]].emplace_back((*it)[1]);
    tree[(*it)[1]].emplace_back((*it)[0]);
  }

  for (auto it = wires.begin(); it != wires.end(); ++it) {
    visited.assign(101, 0);

    // 관계를 순서대로 끊는다.
    int wire = (*it)[1];
    int root = 0;
    queue<int> next;
    next.push(wire);
    visited[wire] = 1;

    while (next.empty() == false) {
      wire = next.front();
      next.pop();
      ++root;

      auto v = tree.find(wire);
      for (auto vit = v->second.begin(); vit != v->second.end(); ++vit) {
        if (visited[*vit] != 1 && *vit != (*it)[0]) {
          next.push(*vit);
          visited[*vit] = 1;
        }
      }
    }

    // 헐 개수의 차이였다고?ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ omg;
    int result = abs(n - (2 * root));
    if (answer > result) {
      answer = result;
    }
  }
  return answer;
}

int main(void) {
  cout << solution(
              9,
              {{1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9}})
       << endl;  // 3
}
