/**
 * @brief 파일 합치기
 * dp.. 어려워 이잉
 * start ~ end 까지의 합에 추가로 더하는 값을 모두 비교하여 최소값을 구한다.
 * dp[start][end] = min(dp[start][k] + dp[k + 1][end] + sum[start 부터 end])
 * 인접 파일을 합쳐가면서 가장 작은 값을 업데이트 해야 한다.
 * 처음엔 정렬 -> 작은 값부터 더하기로 풀었는데 책이기 때문에 인접 페이지만 합칠 수 있다.
 *
 * @link https://www.acmicpc.net/problem/11066
 *
 * @date 2023-11-02
 */
#include <cstring>
#include <iostream>

using namespace std;

int T, K;
int files[501];
int dp[501][501];
int sum[501];

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> T;

  for (int t = 0; t < T; ++t) {
    cin >> K;
    memset(files, 0, 501 * sizeof(int));
    for (int i = 0; i < K; ++i) {
      int num;
      cin >> num;
      files[i] = num;
      sum[i] = (i == 0 ? num : sum[i - 1] + num);
    }

    for (int i = 1; i <= K; ++i) {
      for (int j = 0; j < K - i; ++j) {
        dp[j][j + i] = 1e9;
        // 경우의 수를 나눠서 (j ~ k), (k + 1 ~ j + i) 값을 구한다.
        for (int k = j; k < j + i; ++k) {
          // 추가 연산 (어차피 전체구간 합은 일어남 -> sum) 의 최소를 계산한다
          dp[j][j + i] =
              min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + sum[j + i] -
                                    (j == 0 ? 0 : sum[j - 1]));
        }
      }
    }
    cout << dp[0][K - 1] << '\n';
  }
}
