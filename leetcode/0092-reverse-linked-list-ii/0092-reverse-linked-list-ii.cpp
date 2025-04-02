/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;  // 예외 처리

        // left, right는 1 기반 인덱스다.
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        // dummy를 앞에 두어 head를 백업한다.

        for (int i = 1; i < left; ++i) {
            prev = prev->next; // left 바로 이전
        }

        // prev는 변하지 않는다. prev->next에 앞 놈을 넣는다.
        ListNode *b = prev->next;
        ListNode* c = (b ? b->next : nullptr);
        ListNode *foo = nullptr;

        for (int i = 0; i < right - left; ++i) {
            foo = c ? c->next : nullptr;
            c->next = b;
            b = c;
            c = foo;
        }
        // 3. 연결 복구
        prev->next->next = c;  // 원래 first 노드(b)의 next를 올바르게 연결
        prev->next = b;        // prev의 next를 반전된 첫 번째 노드로 변경

        return dummy.next;
    }
};