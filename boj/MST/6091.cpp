/**
 * @brief 핑크 플로이드
 * 플로이드 워셜이 적용된 트리를 복원하는 문제
 * 크루스칼으로 Minimum spanning tree 를 구해서 푸는 문제이다.
 * 또 서치로 풀었지만 input 정렬 시 애초에 priority queue 로 받는 방식을 배워서 뿌듯하다 ㅎㅎ
 * 크루스칼에서 부모 정하기는 방향이 일정하기만 하면 되는 것 같다.
 * 플로이드 워셜이라고 nxn 배열에 값을 저장할 필요도 없음.
 * @link https://www.acmicpc.net/problem/6091
 *
 * @date 2023-10-16
 */

#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int parents[1025];

int find_root(int n) {
  if (parents[n] == n) {
    return n;
  }
  return parents[n] = find_root(parents[n]);
}

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  priority_queue<pair<int, pair<int, int>>> q;
  int x;

  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      cin >> x;
      q.emplace(-x, make_pair(i, j));
      // 이걸 우선순위 큐를 쓴다고? 천잰데?
    }
    parents[i] = i;
  }

  vector<set<int>> tree(N);

  int cnt = 0;
  while (cnt < N - 1) {
    int cost = -q.top().first;
    int x = q.top().second.first;
    int y = q.top().second.second;

    q.pop();
    // 원래 있는 애들은 애초에 최소
    // 작은 값부터 넣으며 트리가 말이 안되는 경우면 씹음
    // 사이클 판단은 Union find 사용
    if (find_root(x) == find_root(y)) {
      continue;
    }
    // union
    parents[find_root(x)] = find_root(y);

    tree[x].insert(y);
    tree[y].insert(x);
    ++cnt;
  }

  for (int i = 0; i < N; ++i) {
    cout << tree[i].size();
    for (auto it = tree[i].begin(); it != tree[i].end(); ++it) {
      cout << " " << *it + 1;
    }
    cout << "\n";
  }
}
