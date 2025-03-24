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

        ListNode *tail = new ListNode();
        ListNode *head = tail;
        int extra = 0;
        bool first = true;

        while (l1 != nullptr || l2 != nullptr || extra > 0) {
            int now = extra;
            extra = 0;

            if (l1 != nullptr){
                now += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                now += l2->val;
                l2 = l2->next;
            }

            if (now > 9) {
                extra = now / 10;
                now %= 10;
            }
            if (first) {
                tail->val = now;
                first = false;  
            } else {
                tail->next = new ListNode(now);
                tail = tail->next;
            }
        }
        return head;
    } 
};