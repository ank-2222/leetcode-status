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

        if (!head || head->next == nullptr)
            return head;

        int count = right - left + 1;

        ListNode* curr = head;
        ListNode* prev = nullptr; // initialize
        for (int i = 1; i < left; i++) {
            prev = curr;
            curr = curr->next;
        }
        ListNode* tail_ref = curr;
        ListNode* temp = nullptr;
        ListNode* next = nullptr;
        while (curr != nullptr && count--) {
            next = curr->next; // first storing reference of next
            curr->next = temp; // reversing
            temp = curr; // updating previous to next element for 2nd iteration
            curr = next; // updating for while condition
        }

        if(left>1) prev->next = temp;
        else head=temp;
    
        tail_ref->next = next;
        
        return head; // return prev as head
    }
};