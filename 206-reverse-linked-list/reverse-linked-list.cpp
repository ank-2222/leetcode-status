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
    ListNode* reverseList(ListNode* head) {

        if (!head || head->next == nullptr)
            return head;

        ListNode* prev = nullptr;  // initialize
        ListNode* curr = head;
        ListNode* next = nullptr;
        while (curr != nullptr) {

            next = curr->next;  // first storing reference of next
            curr->next = prev;  // reversing
            prev = curr;  //updating previous to next element for 2nd iteration
            curr = next;  //updating for while condition
        }
        return prev;  //return prev as head
    }
};