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
    ListNode* partition(ListNode* head, int x) {

        ListNode* beforeDummy = new ListNode(-1);
        ListNode* afterDummy = new ListNode(-1);

        ListNode* before = beforeDummy;
        ListNode* after = afterDummy;

        ListNode* curr = head;
        while (curr != nullptr) {
            if (curr->val < x) {
                ListNode* temp = curr;
                curr = curr->next;
                before->next = temp;
                before = before->next;
            } else {
                ListNode* temp = curr;
                curr = curr->next;
                after->next = temp;
                after = after->next;
            }
        }
        after->next = nullptr;
        before->next = afterDummy->next;
        return beforeDummy->next;
    }
};