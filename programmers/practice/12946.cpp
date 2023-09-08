/**
 * @brief 하노이의 탑
 * 기본 문제라고 생각했는데 못풀겠더라고?ㅎㅎ.. 구글링을 했다.
 * 리빙포인트! emplace_back({}) 은 안되는데 push_back 은 된다 (value 라서)
 * @link https://school.programmers.co.kr/learn/courses/30/lessons/12946
 *
 * @date 2023-09-08
 */

#include <string>
#include <vector>

using namespace std;

#include <iostream>
void hanoi(vector<vector<int>>& answer, int n, int from, int to, int sub) {
  if (n == 1) {
    answer.push_back({from, to});
    return;
  }

  hanoi(answer, n - 1, from, sub, to);
  answer.push_back({from, to});
  hanoi(answer, n - 1, sub, to, from);
}

// 하노이의 탑
vector<vector<int>> solution(int n) {
  vector<vector<int>> answer;
  // 엄청난 push_back 의 비효율을 막기위한 reserve
  answer.reserve(1280000);
  hanoi(answer, n, 1, 3, 2);
  return answer;
}
