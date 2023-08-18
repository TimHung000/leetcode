#include <string>

class Node{
public:    
    std::string url;
    Node* next;
    Node* prev;
    Node(std::string url, Node* prev=nullptr, Node* next=nullptr): url(url), prev(prev), next(next) {
    }
};

class BrowserHistory {
private:
    Node *cur;
public:
    BrowserHistory(std::string homepage) {
        cur = new Node(homepage);
    }
    
    void visit(std::string url) {
        Node* node = new Node(url);
        cur->next = node;
        node->prev = cur;
        cur = cur->next;
    }
    
    std::string back(int steps) {
        while(cur->prev != nullptr && steps-- > 0)
            cur = cur->prev;
        return cur->url;
    }
    
    std::string forward(int steps) {
        while(cur->next != nullptr && steps-- > 0)
            cur = cur->next;
        return cur->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */