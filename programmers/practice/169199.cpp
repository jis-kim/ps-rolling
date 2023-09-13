/**
 * @brief 리코쳇로봇
 * bfs 로 풀었다
 * @link https://school.programmers.co.kr/learn/courses/30/lessons/169199
 * @date 2023-09-13
 */

#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

int visited[101][101];

int solution(vector<string> board) {
    int answer = 0;
    int maxX = board[0].length() - 1;
    int maxY = board.size() - 1;

    queue<pair<int, int>> bfs;
    int y = 0, x = 0;
    for (y = 0; y < board.size(); ++y) {
        for (x = 0; x < board[0].length(); ++x) {
            if (board[y][x] == 'R') {
                visited[y][x] = 0;
                bfs.emplace(x, y);
            } else {
                visited[y][x] = -1;
            }
        }
    }

    // 멈춘 데 똑같이 멈추면 가망이 없는거임
    while (bfs.empty() == false) {
        auto axis = bfs.front();
        bfs.pop();
        x = axis.first;
        y = axis.second;
        if (board[y][x] == 'G') {
            return visited[y][x];
        }

        int dx = 0, dy = 0;
        while (x + dx >= 0) {
            if (board[y][x + dx] == 'D') {
                break;
            }
            --dx;
        }
        ++dx;
        if (visited[y][x + dx] == -1) {
            visited[y][x + dx] = visited[y][x] + 1;
            bfs.emplace(x + dx, y);
        }
        dx = 0;

        while (x + dx <= maxX) {
            if (board[y][x + dx] == 'D') {
                break;
            }
            ++dx;
        }
        --dx;
        if (visited[y][x + dx] == -1) {
            visited[y][x + dx] = visited[y][x] + 1;
            bfs.emplace(x + dx, y);
        }

        while (y + dy >= 0) {
            if (board[y + dy][x] == 'D') {
                break;
            }
            --dy;
        }
        ++dy;
        if (visited[y + dy][x] == -1) {
            visited[y + dy][x] = visited[y][x] + 1;
            bfs.emplace(x, y + dy);
        }
        dy = 0;
        while (y + dy <= maxY) {
            if (board[y + dy][x] == 'D') {
                break;
            }
            ++dy;
        }
        --dy;
        if (visited[y + dy][x] == -1) {
            visited[y + dy][x] = visited[y][x] + 1;
            bfs.emplace(x, y + dy);
        }
    }

    return -1;
}

int main() {
  vector<string> board = {"...D..R", ".D.G...", "....D.D", "D....D.", "..D...."};
  cout << solution(board) <<endl;  //7
}
