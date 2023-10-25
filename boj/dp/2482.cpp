/**
 * @brief 색상환
 * 겹치지 않게 색깔을 칠하는 문제로 dp[i][j] = dp[i - 2][j - 1] + dp[i - 1][j]로 풀 수 있다.
 * 전자는 i번째 칸을 칠하는 경우의 수, 후자는 칠하지 않는 경우의 수이다.
 *
 * 원형이기 때문에 1번칸 - n번칸의 중복을 고려해아 하므로
 * dp[n][k] 는 dp[n - 3][k - 1] + dp[n][k - 1] 로 풀 수 있다.
 * 전자는 n번째 칸을 칠하는 경우의 수로 1번, N - 1 칸을 제외하고 K - 1개를 칠하는 경우의 수이다.
 * 즉 2번칸부터 N - 2칸까지 K - 1개를 칠하는 경우의 수이므로 dp[n - 3][k - 1]이다.
 * 후자는 n번째 칸을 제외하고 칠하는 경우의 수로 1 ~ N - 1 칸을 k개 칠하는 경우의 수이다.
 *
 * 이해가 잘 안된다 나는 바보인가 보다
 *
 * @link https://www.acmicpc.net/problem/2482
 *
 * @date 2023-10-25
 */

#include <iostream>

using namespace std;

int N, K;
long long dp[1001][1001];
const int MOD = 1000000003;

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> K;
  if (N < K * 2) {
    cout << 0;
    return 0;
  }
  if (N == K * 2) {
    cout << 2;
    return 0;
  }

  for (int i = 0; i <= N; ++i) {
    dp[i][1] = i;
    dp[i][0] = 1;
  }
  for (int i = 2; i <= N; ++i) {
    for (int j = 2; j <= K; ++j) {
      dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
    }
  }

  cout << (dp[N - 1][K] + dp[N - 3][K - 1]) % MOD;
}
