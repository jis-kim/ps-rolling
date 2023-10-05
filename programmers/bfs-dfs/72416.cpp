/**
 * @brief 매출 하락 최소화
 * 흑흑 너무 어려워
 * 해설 봐도 뭔 말인지 모르겠음
 * 이건 내가 푼 게 아니다!!!! 거짓이다!!!!!
 * 암튼 중요한 건 나머지 애들 중 최소값 (참여한 경우 + 참여안한 경우) 를 찾는 거임
 * dfs 로 재귀 내려가는 거 까진 했는데 핵심로직인 참여 하는 경우 / 안하는 경우 구분은 감도 못잡음
 *
 * @link https://school.programmers.co.kr/learn/courses/30/lessons/72416
 *
 * @date 2023-10-05
 */

#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, vector<int>> teams;

// 참석할 경우, 참석하지 않을 경우 최소값
pair<int, int> traversal(int i, vector<int> &sales) {
  if (teams.find(i) == teams.end()) {
    return {0, sales[i - 1]};
  }

  // 내가 참석하지 않았을 경우 -> 나머지 팀원 중 하나가 참석
  // 1-1 한 명이 참석하는 게 이득
  // 1-2 이득은 아니어도 내가 참석 안해서 한 명이 참석
  // 2 내가 참석
  int sum = 0, min_diff = 1e9;
  bool flag = false;
  for (auto mem : teams[i]) {
    auto res = traversal(mem, sales);
    sum += min(res.first, res.second);
    // 참가하는 게 이득인 팀원
    if (res.first >= res.second) {
      flag = true;
    }
    // 참가하지 않는 게 이득일 경우 (flag 가 false) -> min_diff 를 적용
    // 참여 - 노참여 금액이 가장 차이가 적은 팀원을 참여시켜야됨 왜냐면 그래야 손해가 적음
    min_diff = min(min_diff, res.second - res.first);
  }

  // 참가하는 게 이득인 팀원이 있을 경우
  if (flag == true) {
    // 내가 참여 안했으면 sum (누군가는 이미 참여했음), 참여한 경우 (sum + 내 꺼)
    return {sum, sales[i - 1] + sum};
  } else {
    // 내가 참여 안했는데 자연스럽게 얻어진 애가 없으므로 (나머지애들이 참여안하면 안되잖아?) min_diff 를 적용
    // 참여한 경우는 똑같음!
    return {sum + min_diff, sales[i - 1] + sum};
  }
}

int solution(vector<int> sales, vector<vector<int>> links) {
  // sales-> 직원번호, 하루평균 매출액
  // links -> 화살표 시잗 - 티ㅁ장, 받는 쪽 - 팀원
  // 1번은 무조건 CEO
  // 팀 당 1명, 워크샵 참여 직원의 매출액 합이 최소.. 하 이런거 시키지 마삼!!!!!!!!!!!!!

  for (vector<int> &link : links) {
    teams[link[0]].emplace_back(link[1]);
  }
  auto answer = traversal(1, sales);
  return min(answer.first, answer.second);
}

int main(void) {
  cout << solution({14, 17, 15, 18, 19, 14, 13, 16, 28, 17}, {{10, 8},
                                                              {1, 9},
                                                              {9, 7},
                                                              {5, 4},
                                                              {1, 5},
                                                              {5, 10},
                                                              {10, 6},
                                                              {1, 3},
                                                              {10, 2}});

  // 44
}
