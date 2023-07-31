#include <unordered_map>
#include <list>

struct Node {
    int key;
    int value;
    int freq;
    std::list<Node*>::iterator ptr;
    Node(int key, int value, int freq): key(key), value(value), freq(freq) {
    } 
};

class LFUCache
{
private:
    std::unordered_map<int, Node*> keyNodeMap;
    std::unordered_map<int, std::list<Node*>> freqNodeListMap;
    int minFreq;
    int capacity;

public:
    LFUCache(int _capacity) {
        capacity = _capacity;
        minFreq = 0;
    }
    ~LFUCache() {
        for(auto &it: keyNodeMap) {
            delete it.second;
        }
    }

    int get(int key) {
        if (keyNodeMap.find(key) == keyNodeMap.end() || capacity <= 0)
            return -1;

        //update frequency, & return value
        put(key, keyNodeMap[key]->value);
        return keyNodeMap[key]->value;
    }

    void put(int key, int value)
    {
        if (capacity <= 0)
            return;

        // key not in cache
        if (keyNodeMap.find(key) == keyNodeMap.end()) {
            // cache full
            if (keyNodeMap.size() == capacity) {
                Node *nodeToDelete = freqNodeListMap[minFreq].back(); 
                freqNodeListMap[minFreq].pop_back();
                if (freqNodeListMap[minFreq].empty()) {
                    freqNodeListMap.erase(minFreq);
                }
                keyNodeMap.erase(nodeToDelete->key);
                delete nodeToDelete;
            }
            Node *node = new Node(key, value, 1);
            keyNodeMap[key] = node;
            minFreq = 1;
            freqNodeListMap[1].push_front(node);
            node->ptr = freqNodeListMap[1].begin();
        }
        // key in cache
        else {
            Node *node = keyNodeMap[key];
            node->value = value;
            freqNodeListMap[node->freq].erase(node->ptr);
            if (freqNodeListMap[node->freq].empty()) {
                if (minFreq == node->freq)
                    minFreq++;
                freqNodeListMap.erase(node->freq);
            }
            ++node->freq;
            freqNodeListMap[node->freq].push_front(node);
            node->ptr = freqNodeListMap[node->freq].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main() {
    LFUCache* obj = new LFUCache(2);
    obj->put(3, 1);
    obj->put(2, 1);
    obj->put(2, 2);
    obj->put(4, 4);
    obj->get(2);

    return 0;
}