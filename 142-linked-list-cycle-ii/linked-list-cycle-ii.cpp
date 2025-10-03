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
    ListNode* detectCycle(ListNode* head) {

        if (!head || !head->next)
            return nullptr;

        ListNode* curr = head;

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next) {

            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
                break;
        }

        if (!fast || !fast->next)
            return nullptr;
        curr = head;
        while (curr != slow) {

            curr = curr->next;
            slow = slow->next;
        }
        return curr;
    }
};