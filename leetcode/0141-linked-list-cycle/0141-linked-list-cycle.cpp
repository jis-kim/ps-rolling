/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //O(1)메모리로 풀 수 있나요?
        // 순환이 있다면 true, 없다면 false이다.
        ListNode *a = head;
        ListNode *b = head;

        while (b && b->next){
            a = a->next;
            b = b->next->next;

            if (a == b) {
                return true;
            }
        }
        return false;
    }
};