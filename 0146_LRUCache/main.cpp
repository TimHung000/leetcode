#include <unordered_map>
#include <list>
#include <memory>

class Node {
public:
    int key;
    int val;
    std::shared_ptr<Node> next;
    std::shared_ptr<Node> prev;

    Node(int key, int val) : key(key), val(val) {}
};

class LRUCache {
public:
    std::unordered_map<int, std::shared_ptr<Node>> mp;
    int capacity;
    std::shared_ptr<Node> head = std::make_shared<Node>(0, 0);
    std::shared_ptr<Node> tail = std::make_shared<Node>(0, 0);

    LRUCache(int capacity) : capacity(capacity) {
        head->next = tail;
        tail->prev = head;
    }

    void insert(std::shared_ptr<Node> node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        mp[node->key] = node;
    }

    void remove(std::shared_ptr<Node> node) {
        mp.erase(node->key);
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        std::shared_ptr<Node> node = mp[key];
        remove(node);
        insert(node);
        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end())
            remove(mp[key]);

        if (mp.size() == capacity)
            remove(tail->prev);

        insert(std::make_shared<Node>(key, value));
    }
};

class LRUCache1 {
public:
    LRUCache1(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        return getVal(key);
    }

    void put(int key, int value) {
        insertKeyVal(key, value);
    }

private:
    int capacity = 0;
    std::list<std::pair<int, int>> cacheList;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cacheMap;

    int getVal(int key) {
        auto cacheMapIt = this->cacheMap.find(key);
        if(cacheMapIt != this->cacheMap.end()) {
            this->cacheList.splice(this->cacheList.begin(), this->cacheList, cacheMapIt->second);
            return cacheMapIt->second->second;
        }
        else
            return -1;
    }

    void insertKeyVal(int key, int value) {
        auto cacheMapIt = this->cacheMap.find(key);
        if(cacheMapIt != this->cacheMap.end())
            this->cacheList.erase(cacheMapIt->second);

        std::list<std::pair<int, int>>::iterator tmp = this->cacheList.insert(this->cacheList.begin(),std::pair<int, int>(key, value));
        this->cacheMap[key] = tmp;

        if(this->cacheMap.size() > this->capacity) {
            int lastKey = this->cacheList.back().first;
            cacheList.pop_back();
            this->cacheMap.erase(lastKey);
        }
    }

};

