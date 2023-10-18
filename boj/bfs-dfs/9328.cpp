/**
 * @brief 열쇠
 * 살짝 꼬인 BFS 문제로 닫힌 문을 저장해놨다가 key 를 발견하는 순간 enqueue 하는 게 핵심 아이디어
 * 외곽에 key 와 door 가 있다는 것도 고려해야 함
 * 닫힌 문인 상태에서도 주위 칸을 enqueue 했다가 맞왜틀 중이었음 그래도 빨리 찾았다
 *
 * @link https://www.acmicpc.net/problem/9328
 *
 * @date 2023-10-18
 */

#include <cstring>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

int h, w, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
char building[101][101];
bool visited[101][101];
bool keys[26];
int cnt;
string key;

queue<pair<int, int>> q;
set<pair<int, int>> doors[26];

bool check_keys(char c, int x, int y) {
  if (c >= 'a' && c <= 'z') {
    // key 주움
    building[y][x] = '.';
    keys[c - 'a'] = true;
    if (doors[c - 'a'].size() > 0) {
      for (auto d : doors[c - 'a']) {
        q.emplace(d.first, d.second);
      }
      doors[c - 'a'].clear();
    };
    return true;
  } else if (c >= 'A' && c <= 'Z') {
    // 문을 만남
    if (keys[c - 'A'] == true) {
      building[y][x] = '.';
      q.emplace(x, y);
      return true;
    } else {
      doors[c - 'A'].emplace(x, y);
    }
  }
  return false;
}

void find_entrance(int x, int y) {
  char c = building[y][x];
  if (c == '*') {
    return;
  } else if (c == '.' || c == '$') {
    q.emplace(x, y);
  } else {
    check_keys(c, x, y);
  }
}

int bfs(void) {
  // 초기화
  memset(keys, 0, sizeof(keys));
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < 26; ++i) {
    doors[i].clear();
  }

  for (auto s : key) {
    keys[s - 'a'] = true;
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      visited[i][j] = 0;
    }
  }
  cnt = 0;

  for (int i = 0; i < w || i < h; ++i) {
    if (i < w) {
      find_entrance(i, 0);
      find_entrance(i, h - 1);
    }
    if (i < h) {
      find_entrance(0, i);
      find_entrance(w - 1, i);
    }
  }

  while (q.empty() == false) {
    int x = q.front().first;
    int y = q.front().second;
    char c = building[y][x];
    q.pop();

    if (visited[y][x] == true || c == '*') {
      continue;
    }
    bool visit = true;
    if (c == '$') {
      ++cnt;
    } else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
      visit = check_keys(c, x, y);
    }
    if (visit == true) {
      visited[y][x] = true;
    }

    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx >= 0 && nx < w && ny >= 0 && ny < h && visited[ny][nx] == false &&
          building[ny][nx] != '*' && visit == true) {
        q.emplace(nx, ny);
      }
    }
  }
  return cnt;
}

int main(void) {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  int test_case;
  cin >> test_case;

  for (int k = 0; k < test_case; ++k) {
    cin >> h >> w;
    memset(building, 0, sizeof(building));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> building[i][j];
      }
    }
    cin >> key;
    cout << bfs() << '\n';
  }
}
