/**
 * @brief 햄버거 분배
 * greedy 문제
 * 12시 전에 끝내려고 아주아주 쉬운 걸 풀었는데도! 범위체크하다 틀림
 * @link https://www.acmicpc.net/problem/19941
 *
 * @date 2023-10-11
 */

#include <iostream>

using namespace std;

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  int N, K;
  char input[200000];
  int person_cnt;

  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> input[i];
  }

  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    if (input[i] == 'P') {
      for (int j = (i <= K ? 0 : i - K); j < N && j <= i + K; ++j) {
        if (input[j] == 'H') {
          ++cnt;
          input[j] = ' ';
          break;
        }
      }
    }
  }
  cout << cnt;
}
