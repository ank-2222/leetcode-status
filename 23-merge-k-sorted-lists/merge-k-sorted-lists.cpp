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
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min-heap
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for (auto x : lists) {
            if (x)
                pq.push(x);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        while (!pq.empty()) {
            ListNode* temp = pq.top();
            tail->next = temp;
            tail = tail->next;
            if (temp->next) {

                pq.push(temp->next);
            }
            pq.pop();
        }
        return dummy->next;
    }
};