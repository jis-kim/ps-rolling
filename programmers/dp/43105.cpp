/**
 * @brief 이게 3레벨..? 접근법만 알면 쉬운 문제.
 * @link https://school.programmers.co.kr/learn/courses/30/lessons/43105
 *
 * @date 2023-09-01
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 문제가 왤케 짧아?
//   0
//  0 1
// 0 1 2
//0 1 2 3
// 왼쪽-> x 가 같음. 오른쪽 -> x + 1
// 밑에서부터 올라와야하나?.. 두 개씩 보는겨..

int solution(vector<vector<int> > triangle) {
  for (int y = triangle.size() - 1; y > 0; --y) {
    for (int x = 0; x < y; ++x) {
      triangle[y - 1][x] += max(triangle[y][x], triangle[y][x + 1]);
    }
  }

  return triangle[0][0];
}

#include <iostream>

int main(void) {
  vector<vector<int> > triangle = { {7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5} };
  cout << solution(triangle) << endl;
}
