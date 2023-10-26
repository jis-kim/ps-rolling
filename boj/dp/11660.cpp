/**
 * @brief 구간 합 구하기 5
 * 누적합을 잘 구하면 되는 문제다. 1년 전에 틀렸길래 풀었음
 * 쉬웠는데 나의 생각이랑 xy 좌표가 반대였다 왜지?
 * 왜 x y 를 역으로 받응거지....? 내가 이상한걸까?
 * 암튼 input 에서 누적합을 구한 후 출력 시 빼기만 하면 되는 간단한 문제였다!
 * @link https://www.acmicpc.net/problem/11660
 *
 * @date 2023-10-26
 */

#include <iostream>

using namespace std;

int N, M;
int board[1025][1025];

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      int num;
      cin >> num;
      if (i == 0 && j == 0) {
        board[j][i] = num;
      } else if (i == 0) {
        board[j][i] = board[j - 1][i] + num;
      } else if (j == 0) {
        board[j][i] = board[j][i - 1] + num;
      } else {
        board[j][i] =
            board[j][i - 1] + board[j - 1][i] + num - board[j - 1][i - 1];
      }
    }
  }

  for (int i = 0; i < M; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int result = board[y2 - 1][x2 - 1];

    if (x1 > 1) {
      result -= board[y2 - 1][x1 - 2];
    }
    if (y1 > 1) {
      result -= board[y1 - 2][x2 - 1];
    }
    if (x1 > 1 && y1 > 1) {
      result += board[y1 - 2][x1 - 2];
    }
    cout << result << '\n';
  }
}
