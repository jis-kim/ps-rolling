/**
 * @brief 프렌즈4블록
 * ㅎㅎ 2020 카카오 문제인데 난 카카오 못 갈 듯
 * segfalut를 너무 많이 봤다 그냥 iterator 쓸 걸
 * dfs 어쩌구 저시구 필요없고 그냥 n*m 돌면서 2*2 블록의 시작점을 기록해주면
 * 된다. input 외 자료구조를 사용해도 된다는 것을 자꾸 잊는다..... 힌트를 보고
 * 따로 기록할 생각을.. 그 전엔 재귀로 돌다가 이미 지나간 블록때문에 틀렸음...
 * @link https://school.programmers.co.kr/learn/courses/30/lessons/17679
 *
 * @date 2023-09-08
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool checkSquare(vector<string>& board, int w, int h) {
  if (board[h][w] == board[h][w + 1] && board[h][w + 1] == board[h + 1][w] &&
      board[h + 1][w] == board[h + 1][w + 1]) {
    return true;
  }
  return false;
}

int solution(int m, int n, vector<string> board) {
  int answer = 0;
  bool end = false;
  vector<pair<int, int>> co;

  while (end == false) {
    end = true;

    for (auto h = 0; h < m - 1; ++h) {
      for (auto w = 0; w < n - 1; ++w) {
        char character = board[h][w];
        if (character != ' ' && character >= 'A' && character <= 'Z') {
          if (checkSquare(board, w, h) == true) {
            co.emplace_back(w, h);
            if (end == true) {
              end = false;
            }
          }
        }
      }
    }

    for (auto it = co.begin(); it != co.end(); ++it) {
      int w = it->first;
      int h = it->second;
      if (board[h][w] != ' ') {
        board[h][w] = ' ';
        ++answer;
      }
      if (board[h + 1][w] != ' ') {
        board[h + 1][w] = ' ';
        ++answer;
      }
      if (board[h][w + 1] != ' ') {
        board[h][w + 1] = ' ';
        ++answer;
      }
      if (board[h + 1][w + 1] != ' ') {
        board[h + 1][w + 1] = ' ';
        ++answer;
      }
    }
    co.clear();

    // 판 내리기..
    if (end == false) {
      for (auto w = 0; w < n; ++w) {
        int oH = -1;
        for (int h = m - 1; h >= 0; --h) {
          char character = board[h][w];
          if (character == ' ' && oH == -1) {
            oH = h;
          } else if (oH != -1 && board[h][w] != ' ') {
            swap(board[oH][w], board[h][w]);
            h = oH;
            oH = -1;
          }
        }
      }
    }
  }
  return answer;
}

int main(void) {
  cout << solution(4, 5, {"CCBDE", "AAADE", "AAABF", "CCBBF"}) << endl;  // 14

  cout << solution(6, 6,
                   {"IIIIOO", "IIIOOO", "IIIOOI", "IOOIII", "OOOIII", "OOIIII"})
       << endl;  // 32 - 8 or 10 번 case }
}
