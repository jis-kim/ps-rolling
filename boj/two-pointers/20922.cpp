/**
 * @brief 겹치는 건 싫어
 * 투 포인터를 이용해서 푸는 문제다. 완전탐색은 너무 오래 걸리기 때문..
 * 두 가지의 교훈을 얻었음.. 문제를 잘 읽자. 헤더를 잘 쓰자.
 *
 * @link https://www.acmicpc.net/problem/20922
 * @date 2023-10-05
 */

#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;
int main(void) {
  // input
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;
  int arr[200001] = {0};

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  int cnt[200001] = {0};
  int *start = arr;
  int *end = arr;
  int max_len = 0;

  while (end - arr < N) {
    if (cnt[*end] < K) {
      ++cnt[*end];
      ++end;
    } else {
      --cnt[*start];
      ++start;
    }
    max_len = max((int)(end - start), max_len);
  }
  cout << max_len;
}
