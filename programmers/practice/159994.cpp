/**
 * @brief 카드 뭉치
 * AI가 추천해줘서 풀었는데 5분도 안걸렸다. iterator 이용해서 이동하면서 풀었음
 * @link https://school.programmers.co.kr/learn/courses/30/lessons/159994
 *
 * @date 2023-09-07
 */

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2,
                vector<string> goal) {
  auto first = cards1.begin();
  auto second = cards2.begin();

  for (auto it = goal.begin(); it != goal.end(); ++it) {
    if (*first == *it && first != cards1.end()) {
      ++first;
    } else if (*second == *it && second != cards2.end()) {
      ++second;
    } else {
      return "No";
    }
  }
  return "Yes";
}

#include <iostream>

int main(void) {
  vector<string> cards1 = {"i", "drink", "water"};
  vector<string> cards2 = {"want", "to"};
  vector<string> goal = {"i", "want", "to", "drink", "water"};

  cout << solution(cards1, cards2, goal) << endl;  // YES
}
