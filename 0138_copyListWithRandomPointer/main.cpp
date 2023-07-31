#include <unordered_map>
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> map;
        if(head == nullptr)
            return nullptr;
        if(map.find(head) != map.end())
            return map[head];
        
        Node *newNode = new Node(head->val);
        map[head] = newNode;
        newNode->next = copyRandomList(head->next);
        newNode->next = copyRandomList(head->random);
        return newNode;
    }
};

class Solution1 {
public:
    Node* copyRandomList(Node* head) {
        if(!head) 
            return nullptr;
            
        std::unordered_map<Node*, Node*> map;
        map[nullptr] = nullptr;
        Node *ptr = head;
        Node *prev = nullptr;
        while(ptr) {
            if(map.find(ptr) == map.end()) 
                map[ptr] = new Node(ptr->val);

            if(map.find(ptr->random) == map.end())
                map[ptr->random] = new Node(ptr->random->val);
            map[ptr]->random = map[ptr->random];

            if(prev) 
                prev->next = map[ptr];
            prev = map[ptr];
            ptr = ptr->next;
        }

        return map[head];
    }
};

class Solution2 {
public:
    Node* copyRandomList(Node* head) {
        if(!head) 
            return nullptr;
            
        std::unordered_map<Node*, Node*> map;
        map[nullptr] = nullptr;

        Node *ptr = head;
        Node *newNode;
        while(ptr) {
            newNode = new Node(ptr->val);
            map[ptr] = newNode;
            ptr = ptr->next;
        }

        ptr = head;
        while(ptr) {
            newNode = map[ptr];
            newNode->next = map[ptr->next];
            newNode->random = map[ptr->random];
            ptr = ptr->next;
        }
        
        return map[head];
    }
};