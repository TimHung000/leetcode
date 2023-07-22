#include <stack>


class MinStack {
private:
    std::stack<int> data;
    std::stack<int> minStack;
public:
    void push(int x) {
	    data.push(x);
	    if (minStack.empty() || x <= getMin())  
            minStack.push(x);	    
    }
    void pop() {
	    if (data.top() == getMin())  
            minStack.pop();
	    data.pop();
    }
    int top() {
	    return data.top();
    }
    int getMin() {
	    return minStack.top();
    }
};