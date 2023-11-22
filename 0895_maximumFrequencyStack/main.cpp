#include <map>
#include <stack>

class FreqStack {
private:
    std::map<int, int> freqMap;
    std::map<int, std::stack<int>> freqToStackMap;
    int maxFreq;
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        int freq = freqMap[val] + 1;
        freqMap[val] = freq;
        if (freq > maxFreq)
            maxFreq = freq;

        freqToStackMap[freq].push(val);
    }
    
    int pop() {
        int val = freqToStackMap[maxFreq].top();
        freqToStackMap[maxFreq].pop();

        --freqMap[val];
        
        if (freqToStackMap[maxFreq].empty())
            --maxFreq;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */