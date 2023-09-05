/**
 * @brief 카운트 다운
 * 96점 맞았다... dp 문젠데 말 안들어서 그런것일까?
 * 불을 구하고 트리플로 교체하는 식으로 (greedy 느낌?..) 진행했는데 20번
 * 케이스가 틀렸다. 질문하기에 있는 테스트 케이스는 다 통과되고 자료는 너무
 * 없길래 여기서 중단....
 * @link https://school.programmers.co.kr/learn/courses/30/lessons/131129
 *
 * @date 2023-09-06
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1. dp 문제로 분할하여 해를 구한다.
// case 를 나눠서 작은 수 저장 -> 큰 수에 반영하는 식
// 2. 불 + 싱글로 구한 후 트리플로 교체

// target -> 1 ~ 100000
vector<int> solution(int target) {
  vector<int> answer;

  if (target <= 20 || target == 50) {
    answer = {1, 1};
  } else if (target < 300 && target % 50 == 0) {
    answer = {target / 50, target / 50};
  } else {
    // 2번 방법
    answer = {100000, 0};
    int bullCount = target / 50;
    int tripleCount = 0;

    while (bullCount >= 0) {
      int mod = target - 50 * bullCount - 60 * tripleCount;
      if (mod < 0) {
        while (mod + 60 < 60) {
          --tripleCount;
          mod += 60;
        }
      }

      int candidate[2] = {0, 0};
      if (mod <= 20) {
        candidate[0] = bullCount + tripleCount + 1;
        candidate[1] = bullCount + 1;
      } else if (mod <= 40) {
        if (mod % 2 == 0 || mod % 3 == 0) {
          candidate[0] = bullCount + tripleCount + 1;
          candidate[1] = bullCount;
        } else {
          candidate[0] = bullCount + tripleCount + 2;
          candidate[1] = bullCount + 2;
        }
      } else {
        if (mod % 3 == 0) {
          candidate[0] = bullCount + tripleCount + 1;
          candidate[1] = bullCount;
        } else {  // 41 ~ 59 ?
          candidate[0] = bullCount + tripleCount + 2;
          candidate[1] = bullCount + 1;
        }
      }

      if (answer[0] > candidate[0] ||
          (answer[0] == candidate[0] && answer[1] < candidate[1])) {
        answer[0] = candidate[0];
        answer[1] = candidate[1];
      }
      --bullCount;
      ++tripleCount;
    }
  }
  return answer;
}

int main(void) {
  auto answer = solution(21);
  cout << answer[0] << ", " << answer[1] << endl;  // 1, 0

  answer = solution(58);
  cout << answer[0] << ", " << answer[1] << endl;  // 2, 2
}
