#include <queue>
#include <vector>
#include <functional>
using namespace std;

class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() = default;
    
    void addNum(int num) {
        if(maxHeap.size() == minHeap.size())
        {
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else
        {
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size()== minHeap.size())
            return (double)(maxHeap.top() + minHeap.top()) / 2;
        else
            return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */