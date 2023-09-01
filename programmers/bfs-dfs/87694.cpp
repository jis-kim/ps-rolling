/**
 * @brief 교훈: 사람들이 가지 않는 길에는 이유가 있다.
 * @link https://school.programmers.co.kr/learn/courses/30/lessons/87694
 *
 * @date 2023-08-30
 */

#include <queue>
#include <string>
#include <vector>

// rectangle -> 지형
// characterX, characterY -> 초기 캐릭터 위치
// itemX, itemY -> 초기 아이템 위치
// 이게 왜 dfs bfs 지? .. 개어려움....
// 1. 이동경로 구하고 왼쪽/오른쪽 중에 판별하기
// 2. 왼쪽 냅다가보기/오른쪽냅다가보기....

const int EMPTY = 0;
const int HOR = 1;

// r, l, d, u
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

// int direction[52][52];

int getDistBfs(int map[103][103], int ox, int oy, int ix, int iy) {
  // x, y
  std::queue<std::pair<int, int>> q;
  q.emplace(ox, oy);

  int first = 0;

  while (q.empty() == false) {
    int cx = q.front().first;
    int cy = q.front().second;
    q.pop();

    if (cx == ix && cy == iy) {
      break;
    }
    for (int i = 0; i < 4; ++i) {
      int nextY = cy + dy[i];
      int nextX = cx + dx[i];

      if (map[nextY][nextX] == 1) {
        q.emplace(nextX, nextY);
        map[nextY][nextX] = map[cy][cx] + 1;
      }
    }
    /*
    int dir  = direction[cy][cx];
    if (dir >= 2) { // VER
        // 수평 먼저 접근
        for (int i = 0; i < 4; ++i)
        {
            int nextY = cy + dy[i];
            int nextX = cx + dx[i];
            // 수평 접근 혹은 수직이면서 방향이 다름.
            if (map[nextY][nextX] == 1 && (i < 2 || i == dir)){
                q.emplace(nextX, nextY);
                map[nextY][nextX] = map[cy][cx] + 1;
                direction[nextY][nextX] = i;
                break;
            }
        }
    } else { // 수평
        for (int i = 3; i >= 0; --i)
        {
            int nextY = cy + dy[i];
            int nextX = cx + dx[i];

            // 초기값 혹은 수직 혹은 수평인데 다른방향
            if (map[nextY][nextX] == 1 && (i >= 2 || i == dir)) {
                q.emplace(nextX, nextY);
                map[nextY][nextX] = map[cy][cx] + 1;
                direction[nextY][nextX] = i;
                break;
            }
        }
    }
    */
  }

  return map[iy][ix] - 1;
}

/*
int getDist(int map[52][52], int ox, int oy, int ix, int iy) {

    int prevDirection = -1;
    int dist = 0;

    int d1 = -1;
    int cx = ox;
    int cy = oy;

    while (d1 == -1 || !(cx == ox && cy == oy)) {
        if (d1 == -1 && cx == ix && cy == iy) {
            d1 = dist;
            return dist;
            dist = 0;
        }

        int cur = map[cy][cx];

        int right = map[cy][cx + 1];
        int left = map[cy][cx - 1];

        int down = map[cy + 1][cx];
        int up = map[cy - 1][cx];

        // std::cout << (cur == VER ? "VER" : "HOR") << " x: "<< cx << ", y: "
<< cy<< std::endl;
        // std::cout << "r, u, l, d\n" << right << ", " << up<< ", " << left <<
", " << down << "\n";

        if (prevDirection == 0 || prevDirection == 2) {
            // 가로로 왔을 경우
            if (down != EMPTY) {
                ++cy;
                prevDirection = 1;
            } else if (up != EMPTY) {
                --cy;
                prevDirection = 3;
            } else if (right != EMPTY && prevDirection != 2) { // 왼쪽에서 온 게
아님
                ++cx;
                prevDirection = 0;
            } else if (left != EMPTY && prevDirection != 0) { // 오른쪽에서 온
게 아님
                // 왼쪽으로 고고
                --cx;
                prevDirection = 2;
            }
        }
        else {
            // 세로로 왔을 경우
            if (right != EMPTY) {
                // right ㄱㄱ
                ++cx;
                prevDirection = 0;
            } else if (left != EMPTY) {
                // 왼쪽으로 고고
                --cx;
                prevDirection = 2;
            } else if (down != EMPTY && prevDirection != 3) {
                ++cy;
                prevDirection = 1;
            } else if (up != EMPTY && prevDirection != 1) {
                --cy;
                prevDirection = 3;
            }
        }

        if (!(cx == ox && cy == oy) && !(cx == ix && cy == iy)) {
            map[cy][cx] = EMPTY;
        }
        ++dist;
    }
    return std::min(d1, dist);
}
*/

int solution(std::vector<std::vector<int>> rectangle, int characterX,
             int characterY, int itemX, int itemY) {
  // int map[52][52] = { 0 };
  int map[103][103] = {0};

  characterX *= 2;
  characterY *= 2;
  itemX *= 2;
  itemY *= 2;

  for (auto it = rectangle.begin(); it != rectangle.end(); ++it) {
    auto rectangle = *it;  // x1, y1, x2, y2
    int x1 = rectangle[0] * 2;
    int x2 = rectangle[2] * 2;
    int y1 = rectangle[1] * 2;
    int y2 = rectangle[3] * 2;

    // 가로선
    for (int w = x1; w <= x2; ++w) {
      map[y1][w] = HOR;
      map[y2][w] = HOR;
    }
    // 세로선
    for (int h = y1; h <= y2; ++h) {
      map[h][x1] = HOR;
      map[h][x2] = HOR;
    }
  }
  /*
  int maxX1 = 1, maxY1 = 1;
  int minX2 = 50, minY2 = 50;
  */

  // 그은 선이 다른 사각형의 내부일 경우 삭제한다.
  for (auto it = rectangle.begin(); it != rectangle.end(); ++it) {
    auto rectangle = *it;  // x1, y1, x2, y2
    int x1 = rectangle[0] * 2;
    int x2 = rectangle[2] * 2;
    int y1 = rectangle[1] * 2;
    int y2 = rectangle[3] * 2;
    /*
    if (maxX1 < x1) {
        maxX1 = x1;
    }
    if (maxY1 < y1) {
        maxY1 = y1;
    }
    if (minX2 > x2){
        minX2 = x2;
    }
    if (minY2 > y2){
        minY2 = y2;
    }
    */

    // (이게맞냐?...)
    for (int w = x1 + 1; w < x2; ++w) {
      for (int h = y1 + 1; h < y2; ++h) {
        if (map[h][w] != EMPTY) {
          map[h][w] = EMPTY;
        }
      }
    }
  }

  /*
  // 중앙의 빈공간 삭제
  for (int w = minX2; w <= maxX1; ++w) {
      for (int h = minY2; h <= maxY1; ++h) {
          if (map[h][w] != EMPTY) {
              map[h][w] = EMPTY;
          }
      }
  }*/

  //     // map print
  //     for (int j = 49; j >= 0; --j) {
  //         for (int i = 0; i < 50; ++i) {
  //             std::cout << map[j][i] << "," ;
  //         }
  //         std::cout << std::endl;
  //     }
  //     // return 0;

  // return getDist(map, characterX, characterY, itemX, itemY);
  return getDistBfs(map, characterX, characterY, itemX, itemY) / 2;
}

#include <iostream>
int main(void) {
  std::vector<std::vector<int>> case1 = {
      {1, 1, 7, 4}, {3, 2, 5, 5}, {4, 3, 6, 9}, {2, 6, 8, 8}};
  int s1 = solution(case1, 1, 3, 7, 8);
  std::cout << s1 << std::endl;  // 17

  std::vector<std::vector<int>> case2 = {
      {1, 1, 8, 4}, {2, 2, 4, 9}, {3, 6, 9, 8}, {6, 3, 7, 7}};
  int s2 = solution(case2, 9, 7, 6, 1);
  std::cout << s2 << std::endl;  // 11

  std::vector<std::vector<int>> case3 = {{1, 1, 5, 7}};
  int s3 = solution(case3, 1, 1, 4, 7);
  std::cout << s3 << std::endl;  // 9

  std::vector<std::vector<int>> case4 = {{2, 1, 7, 5}, {6, 4, 10, 10}};
  int s4 = solution(case4, 3, 1, 7, 10);
  std::cout << s4 << std::endl;  // 15

  // [[2, 1, 3, 6], [4, 1, 5, 6], [1, 2, 6, 3], [1, 4, 6, 5]]
  std::vector<std::vector<int>> case5 = {
      {2, 1, 3, 6}, {4, 1, 5, 6}, {1, 2, 6, 3}, {1, 4, 6, 5}};
  int s5 = solution(case5, 3, 2, 5, 4);
  std::cout << s5 << std::endl;  // 8
}
