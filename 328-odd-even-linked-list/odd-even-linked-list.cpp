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
    ListNode* oddEvenList(ListNode* head) {
         ListNode* oddDummy = new ListNode(-1);
        ListNode* evenDummy = new ListNode(-1);

        ListNode* odd = oddDummy;
        ListNode* even = evenDummy;

        ListNode* curr = head;
        int n=1;
        while (curr != nullptr) {
            if (n%2==0) {
                ListNode* temp = curr;
                curr = curr->next;
                even->next = temp;
                even = even->next;
            } else {
                ListNode* temp = curr;
                curr = curr->next;
                odd->next = temp;
                odd = odd->next;
            }
            n++;
        }
        even->next = nullptr;
        odd->next = evenDummy->next;
        return oddDummy->next;
    }
};