/**
 * @brief 고층 건물
 * 뭐지?.. 골드 4치고 쉬웠다. 내가 백준 기준을 잘못 알고 있는 건지..?
 * 근데 나의 절반 메모리로 푼 사람이 많아서 충격 max
 * @link https://www.acmicpc.net/problem/1027
 *
 * @date 2023-10-14
 */

#include <cmath>
#include <iostream>

using namespace std;

int buildings[50];

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> buildings[i];
  }

  int max_cnt = 0;
  for (int i = 0; i < N; ++i) {
    int cnt = 0;
    for (int j = 0; j < N; ++j) {
      int flag = false;
      if (i != j) {
        double a = (double)(buildings[j] - buildings[i]) / (double)(j - i);
        double b = buildings[i];

        for (int k = i + 1; k < j; ++k) { // i ~ k ~ j
          if (buildings[k] >= a * (k - i) + b) {
            flag = true;
          }
        }
        for (int k = i - 1; k > j; --k) { // j ~ k ~ i
          if (buildings[k] >= a * (k - i) + b) {
            flag = true;
          }
        }
        if (flag == false) {
          ++cnt;
        }
      }
      max_cnt = max(max_cnt, cnt);
    }
  }
  cout << max_cnt;
}
