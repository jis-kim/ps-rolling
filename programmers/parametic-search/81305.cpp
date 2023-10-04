/**
 * @brief 시험장 나누기
 * 아오 어쩐지 어렵더라 lv5네 ㅋㅋㅋㅋㅋㅋ 이걸 왜 추천해주는!!!!
 * 너무너무 어려웠다 ㅎㅎ 하나도 모르겠어서 검색해서 풀었다. 맨날 검색해서 푸는듯?ㅎㅎ..
 * 최대 그룹의 크기 -> 그룹 크기를 n 으로 정하고 k개가 되는 지 탐색으로 변형하여 이진탐색.
 * 주어진 조건에서 값을 찾는 탐색법을 parametric search 라고 한다.
 * 로직은 (베껴서) 좋았는데 범위때문에 자꾸 틀렸다.
 * 1. 이진 탐색 범위 잘 정해야 함
 * 2. 함수 call 매개변수 너무 많으면 헷갈림......ㅋㅋㅋㅋㅋㅋㅋ
 * 처음에 cnt와 mid 를 바꿔 넣어서 cnt 가 0이 되었음. 함수 정의를 바꾼 후엔 호출부를 잘 살펴보자.
 * 여기다 dp 를 적용하는 경우도 있던데 계속 값이 바뀌는 경우라서 의미가 있는 지 모르겠음
 * bottom up 이라 필요 없었을 수도?
 *
 * @link https://school.programmers.co.kr/learn/courses/30/lessons/81305
 *
 * @date 2023-10-04
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>

using namespace std;

// 트리를 k개 이하의 그룹으로 나누어서 얻을 수 있는 최대 그룹의 크기가 L 이하가 되도록 할 수 있는가
// 그룹의 수, 각 시험장의 응시자 수, 연결 상태
void find_root(int i, array<int, 10001> &visited, vector<vector<int>> &links) {
  visited[i] = 1;
  if (links[i][0] != -1) {
    find_root(links[i][0], visited, links);
  }
  if (links[i][1] != -1) {
    find_root(links[i][1], visited, links);
  }
}

// bottom-up 방식으로 탐색한다.
int traversal(int cur, int mid, int &cnt, vector<int> &num,
              vector<vector<int>> &links) {
  // leaf node

  int value = num[cur];
  if (links[cur][0] == -1 && links[cur][1] == -1) {
    return value;
  }

  int left = 0, right = 0;
  if (links[cur][0] != -1) {
    left = traversal(links[cur][0], mid, cnt, num, links);
  }
  if (links[cur][1] != -1) {
    right = traversal(links[cur][1], mid, cnt, num, links);
  }

  if (value + left + right <= mid) {
    // 그룹 그대로
    return value + left + right;
  }
  if (value + min(left, right) <= mid) {
    ++cnt; // 큰 그룹은 grouping
    return value + min(left, right);
  }
  cnt += 2;
  return value;
}

int solution(int k, vector<int> num, vector<vector<int>> links) {
  // 가장 큰 그룹의 인원을 최소화.. 된 최대 그룹의 인원을 return (int)
  // num[index]
  long long total = accumulate(num.begin(), num.end(), 0);
  if (k == 1) {
    return total;
  }
  array<int, 10001> visited;
  memset(visited.data(), 0, visited.size() * sizeof(visited[0]));

  int root = 0;
  for (int i = 0; i < links.size(); ++i) {
    if (visited[i] != 1) {
      root = i;
      find_root(i, visited, links);
    }
  }

  int start = *max_element(num.begin(), num.end());
  int end = total;
  int mid = 0;

  while (start < end) {
    mid = (start + end) / 2;
    int cnt = 0;
    traversal(root, mid, cnt, num, links);
    if (cnt > k - 1) {
      // 더 잘게 나눠짐 -> 값을 늘린다
      start = mid + 1;
    } else {
      // 더 크게 나눠짐 -> 값을 줄인다. (최소 구하기)
      end = mid;
    }
  }
  return end;
}

int main(void) {
  // call solution
  cout << solution(3, {12, 30, 1, 8, 8, 6, 20, 7, 5, 10, 4, 1},
                   {{-1, -1},
                    {-1, -1},
                    {-1, -1},
                    {-1, -1},
                    {8, 5},
                    {2, 10},
                    {3, 0},
                    {6, 1},
                    {11, -1},
                    {7, 4},
                    {-1, -1},
                    {-1, -1}})
       << endl;
}
