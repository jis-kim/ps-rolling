/**
 * @brief 올바른 괄호의 갯수
 * 전형적인 dp 문제이나 점화식 세우는 게 어렵다.
 * 괄호 하나를 놓고 (무조건 바른 괄호만 오기 때문에) 그 안에 들어갈 쌍 / 밖에 있을 쌍으로 구분하면 된다.
 * 만약 4개라면 0/3, 1/2, 2/1, 3/0 의 경우를 다 더해주면 된다.
 *
 * @link https://school.programmers.co.kr/learn/courses/30/lessons/12929
 *
 * @date 2023-10-08
 */

#include <string>
#include <vector>

using namespace std;

int dp[15];

int solution(int n) {
  dp[0] = 1;
  dp[1] = 1;

  // 왼쪽에 () 를 두고 괄호 안에 들어갈 갯수 * 밖에 나올 갯수로 구한다.
  for (int i = 2; i <= n; ++i) {
    for (int j = i - 1; j >= 0; --j) {
      dp[i] += dp[i - j - 1] * dp[j];
    }
  }
  return dp[n];
}

#include <iostream>
int main(void) {
  cout << solution(3) << endl;
  cout << solution(4) << endl; // 14
}
