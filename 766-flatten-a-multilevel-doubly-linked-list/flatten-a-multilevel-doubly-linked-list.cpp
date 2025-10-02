/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {

        stack<Node*> st;
        Node* curr = head;

        while (curr != nullptr) {
            if (curr->child != nullptr) {
                if (curr->next != nullptr)
                    st.push(curr->next);
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
            } else if (curr->next == nullptr && !st.empty()) {
                Node* temp = st.top();
                st.pop();
                curr->next = temp;
                if (temp)
                    temp->prev = curr;
            }

            curr = curr->next;
        }

        return head;
    }
};