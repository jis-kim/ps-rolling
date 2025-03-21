class Solution {
public:
    // non-decreasing order: 중복 숫자가 있을 수 있는, 오름차순 정렬.
    // decreasing은 .. 줄어드는(내림차순) 정렬이니깐 ㅋ
    int removeDuplicates(vector<int>& nums) {
        /** 수도코드
        * 0 ~ n 돈다.
        1. 앞으로 가는 iterator
        이전 나온 숫자와 중복이면 -> 중복 다음 숫자에 복사.
        중복이 아니면 -> next
        2. 중복 위치를 저장하는 iterator
        중복이면 다음으로 이동 후 끝낸다.
        그리고 k를 ++한다.
        **/

        int k = 1; // 1개 이상이므로 ㄱㅊㄱㅊ
        auto cur = nums.begin();
        auto sorted = nums.begin();

        for (; cur != nums.end(); ++cur) {
            if (*cur > *sorted) {
                *(++sorted) = *cur;
                ++k;
            }
        }
        return k;
    }
};