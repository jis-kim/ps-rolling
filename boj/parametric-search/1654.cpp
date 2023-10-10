/**
 * @brief 랜선 자르기
 * 기본적인 parametric search 이다.
 * 연산 횟수 줄이려고 쓸 데 없는 quotient check 넣었다가 틀렸다...흑흑
 * 랜선 하나가 자르려는 길이보다 작은 경우는 pass 했는데 ..
 * 다른 랜선을 여러 번 자르면 결국 N 개의 랜선을 가질 수 있기 때문에
 * 이미 갖고 있던 랜선이 지나치게 짧아도 별 상관이 없었다.
 * 하나만 생각하고 둘은 생각하지 못한 어리석은 나
 * 그리고 이분 탐색 할 때는 항상 start, end 업데이트가 어려운 것 같다. 생각을 깊이 해보고 하자..
 * TDD 하지말고.....ㅎㅎ
 *
 * @link https://www.acmicpc.net/problem/1654
 *
 * @date 2023-10-10
 */

#include <cmath>
#include <iostream>

using namespace std;
long long length[10001];

int main(void) {
  // input
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  int K, N;
  cin >> K >> N;
  for (int i = 0; i < K; i++) {
    cin >> length[i];
  }

  // 랜선의 길이
  long long start = 1;
  long long end = pow(2, 31) - 1;
  while (start < end) {
    // mid = (L+R)/2 로 계산할 경우 - 시간 초과
    // Y Y Y Y Y N N N 꼴이기 때문에 mid = ceil((L+R)/2) = (L+R+1)/2 여야 함
    long long mid = (start + end + 1) / 2;
    long long cnt = 0;

    long long quotient = mid;
    for (int i = 0; i < K; ++i) {
      cnt += length[i] / mid;
    }
    if (cnt >= N) {
      start = mid;
    } else {
      end = mid - 1;
    }
  }
  cout << start;
}
