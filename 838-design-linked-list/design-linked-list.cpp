class MyLinkedList {
    private:
    struct ListNode {
        int val;
        ListNode* prev;
        ListNode* next;
        ListNode(int x = 0) : val(x), prev(nullptr), next(nullptr) {}
    };

    ListNode* head; // dummy head
    ListNode* tail; // dummy tail
    int size;       // number of elements

public:
    MyLinkedList() {
        head = new ListNode(); 
        tail = new ListNode();
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        ListNode* curr = head->next;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        
        ListNode* pred = head;
        for (int i = 0; i < index; i++) {
            pred = pred->next;
        }
        ListNode* succ = pred->next;
        
        ListNode* node = new ListNode(val);
        node->prev = pred;
        node->next = succ;
        pred->next = node;
        succ->prev = node;
        
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        
        ListNode* pred = head;
        for (int i = 0; i < index; i++) {
            pred = pred->next;
        }
        ListNode* toDelete = pred->next;
        ListNode* succ = toDelete->next;
        
        pred->next = succ;
        succ->prev = pred;
        delete toDelete;
        
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */