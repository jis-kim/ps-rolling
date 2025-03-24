#include <stdio.h>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 역순 저장, 하나의 digit 저장. (int type) (반대임을 명심)
        // l1 혹은 l2의 끝에 다다를 때까지

        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int extra = 0;

        while (l1 != nullptr || l2 != nullptr || extra > 0) {
            int now = extra;

            if (l1 != nullptr){
                now += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                now += l2->val;
                l2 = l2->next;
            }
            
            extra = now / 10;
            now %= 10;

            if (head == nullptr) {
                head = tail = new ListNode(now % 10);
            } else {
                tail = tail->next = new ListNode(now % 10); // 생성자 활용
            }
        }
        return head;
    } 
};