/**
 * @brief 길 찾기 게임
 * korean so weird in vsc :( So I use English instead
 * this problem so gury gury
 * I want to use map but I can't because map dosen't have left and right pointer
 * I wasted my time omg so sad
 * and check range plz !! check min and max input value!!!!!!! I'm babo!
 * so tired
 *
 * @link https://school.programmers.co.kr/learn/courses/30/lessons/42892
 *
 * @date 2023-09-12
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Tree {
  Tree* left = NULL;
  Tree* right = NULL;
  int index;
};

void preOrder(vector<int>& answer, Tree* node) {
  if (node == NULL) return;
  answer.emplace_back(node->index);
  preOrder(answer, node->left);
  preOrder(answer, node->right);
}

void postOrder(vector<int>& answer, Tree* node) {
  if (node == NULL) return;
  postOrder(answer, node->left);
  postOrder(answer, node->right);
  answer.emplace_back(node->index);
}

Tree* makeTree(vector<vector<int>>& nodeinfo, vector<vector<int>>::iterator it,
               int min, int max) {
  if (it == nodeinfo.end()) {
    return NULL;
  }

  Tree* node = new Tree();
  node->index = (*it)[2];

  int x = (*it)[0];
  int y = (*it)[1];

  while (it != nodeinfo.end() && y == (*it)[1]) {  // 다음 level
    ++it;
  }

  for (auto next = it; next != nodeinfo.end() && (*next)[1] == (*it)[1];
       ++next) {
    if ((*next)[0] >= min && (*next)[0] < max) {
      if ((*next)[0] <= x) {
        node->left = makeTree(nodeinfo, next, min, x);
      } else {
        node->right = makeTree(nodeinfo, next, x + 1, max);
      }
    }
  }

  return node;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
  vector<vector<int>> answer;

  // n (10000) 회
  int index = 1;
  for (auto it = nodeinfo.begin(); it != nodeinfo.end(); ++it) {
    it->emplace_back(index++);
  }
  // logN
  sort(nodeinfo.begin(), nodeinfo.end(), [](vector<int>& x, vector<int>& y) {
    return (x[1] > y[1] || (x[1] == y[1] && x[0] < y[0]));
  });

  answer.emplace_back();
  answer[0].reserve(10000);
  answer.emplace_back();
  answer[1].reserve(10000);

  Tree* head;
  head = makeTree(nodeinfo, nodeinfo.begin(), 0, 100001);

  preOrder(answer[0], head);
  postOrder(answer[1], head);

  return answer;
}

int main(void) {
  vector<vector<int>> nodeinfo = {{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1},
                                  {1, 3}, {8, 6},  {7, 2},  {2, 2}};
  solution(nodeinfo);
}
