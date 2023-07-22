#include <vector>
#include <stack>
class Solution {
public:
    bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped) {
        std::stack<int> st;
        int i = 0;
        for(int val: pushed) {
            st.push(val);
            while(i < popped.size() && !st.empty() && st.top() == popped[i]) {
                st.pop();
                ++i;
            }
        }
        return st.empty();
    }
};