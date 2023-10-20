/**
 * @brief 말이 되고픈 원숭이
 * BFS + visited 변형.
 * 말처럼 움직일 수 있는 횟수도 visited 에서 알 수 있어야 한다.
 * 맨 처음엔 2차원 배열으로 일반적으로 접근했다가 틀렸다.!
 *
 * @link
 *
 * @date 2023-10-19
 */

#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

int K, W, H;
int board[201][201];
int visited[201][201][31];

int dx[12] = {-1, 1, 0, 0, -2, -2, 2, 2, -1, 1, -1, 1};
int dy[12] = {0, 0, -1, 1, -1, 1, -1, 1, -2, -2, 2, 2};

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> K >> W >> H;

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> board[i][j];
    }
  }

  // 남은 횟수, x, y
  queue<pair<int, pair<int, int>>> q;
  q.emplace(K, make_pair(0, 0));
  visited[0][0][K] = 1;

  while (q.empty() == false) {
    int k = q.front().first;
    int x = q.front().second.first;
    int y = q.front().second.second;
    q.pop();

    for (int i = 0; i < 12; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (i >= 4 && k == 0) {
        break;
      }
      if (nx >= 0 && nx < W && ny >= 0 && ny < H && board[ny][nx] == 0) {
        if (i >= 4 && visited[ny][nx][k - 1] == 0) {
          visited[ny][nx][k - 1] = visited[y][x][k] + 1;
          q.emplace(k - 1, make_pair(nx, ny));
        } else if (i < 4 && visited[ny][nx][k] == 0) {
          visited[ny][nx][k] = visited[y][x][k] + 1;
          q.emplace(k, make_pair(nx, ny));
        }
      }
    }
  }

  int min_val = 1e9;
  for (int i = 0; i <= K; ++i) {
    if (visited[H - 1][W - 1][i] != 0) {
      min_val = min(min_val, visited[H - 1][W - 1][i] - 1);
    }
  }
  if (min_val == 1e9)
    cout << -1;
  else
    cout << min_val;
  return 0;
}
