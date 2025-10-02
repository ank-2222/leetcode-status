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

    ListNode* reverseList(ListNode* head) {

        if (!head || head->next == nullptr)
            return head;

        ListNode* prev = nullptr; // initialize
        ListNode* curr = head;
        ListNode* next = nullptr;
        while (curr != nullptr) {

            next = curr->next; // first storing reference of next
            curr->next = prev; // reversing
            prev = curr; // updating previous to next element for 2nd iteration
            curr = next; // updating for while condition
        }
        return prev; // return prev as head
    }

public:
    bool isPalindrome(ListNode* head) {

        if (!head || head->next == nullptr)
            return head;

        ListNode* curr = head;
        ListNode* fast = curr;
        ListNode* slow = curr;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // after loop ends slow is in mid and fast at end
        ListNode* newHead = reverseList(slow->next);
        slow->next = newHead;

        ListNode* p1 = head;
        ListNode* p2 = newHead; // reversed second half
        while (p2 != nullptr) {
            if (p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }
    return true;
    }
};