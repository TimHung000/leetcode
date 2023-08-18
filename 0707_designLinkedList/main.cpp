class Node {
public:
    int val;
    Node *next;
    Node(int val, Node* next=nullptr): val(val), next(next){}
};

class MyLinkedList {
private:
    int size;
    Node *head;
public:
    MyLinkedList(): size(0), head(nullptr) {
    }
    ~MyLinkedList() {
        while(head) {
            Node *tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    
    int get(int index) {
        if(index >= size || index < 0)
            return -1;
        Node *cur = head;
        while(index--)
            cur = cur->next;
        return cur->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val) {
        if(index > size || index < 0)
            return;
        
        Node **cur = &head;
        while(index--)
            cur = &((*cur)->next);
        
        Node *newNode = new Node(val, *cur);
        *cur = newNode;
        ++size;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size || index < 0)
            return;
        
        Node **cur = &head;
        while(index--)
            cur = &((*cur)->next);
        
        Node *tmp = *cur;
        *cur = (*cur)->next;
        delete tmp;
        --size;
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