#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    std::string removeStars(std::string s) {
        std::string res;
        for(char ch: s) {
            if(ch == '*')
                res.pop_back();
            else
                res.push_back(ch);
        }
        return res;
    }
};

class Solution {
public:
    std::string removeStars(std::string s) {
        std::stack<char> st;
        
        for (char c : s) {
            if (c == '*' && !st.empty())
                st.pop();
            else
                st.push(c);
        }
        
        std::string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};