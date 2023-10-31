/**
 * @brief 선 긋기
 * 왜 헷갈리게 좌표 하나 뿐인데 xy 라고 해둔거임?
 * 그리디인 거 몰라도 쉬운 문제였다. (x,y)형태였으면 5배쯤 어려웠을 듯
 * @link https://www.acmicpc.net/problem/2170
 *
 * @date 2023-10-31
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> lines;

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;

  for (int i = 0; i < N; ++i) {
    pair<int, int> p;
    cin >> p.first >> p.second;
    if (p.first > p.second) {
      swap(p.first, p.second);
    }
    lines.push_back(p);
  }
  sort(lines.begin(), lines.end());

  auto it = lines.begin();
  int begin = it->first, end = it->second;
  int result = 0; // 최대 2억
  for (; it != lines.end(); ++it) {
    if (end < it->first || begin > it->second) {
      result += end - begin;
      begin = it->first;
      end = it->second;
    } else {
      end = max(end, it->second);
      begin = min(begin, it->first);
    }
  }
  result += end - begin;
  cout << result;
}
