/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        Node* curr = head;

        while(curr){
            Node* copy = new Node(curr->val);
            Node* temp = curr->next;
            curr->next=copy;
            copy->next = temp;
            curr=curr->next->next;

        }

        Node* original =head;
        while(original){
            if(original->random != NULL){
                original->next->random = original->random->next;
            }
            original=original->next->next;
        }

        Node* newHead = new Node(-1); 
        Node* newH = newHead;
        Node* newcurr = head;  
        while(newcurr){
          Node* copy = newcurr->next;
          newcurr->next= copy->next;
          newH->next = copy;
          newH=newH->next;
          newcurr=newcurr->next;
            
        }
        return newHead->next;
    }
};