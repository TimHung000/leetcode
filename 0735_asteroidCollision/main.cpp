#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::stack<int> st;
        bool destroy;
        for(int val: asteroids) {
            destroy = false;
            while(!st.empty() && st.top() > 0 && val < 0 && destroy == false) {
                if(val + st.top() < 0)
                    st.pop();
                else if(val + st.top() > 0)
                    destroy = true;
                else {
                    st.pop();
                    destroy = true;
                }
            }
            if(!destroy)
                st.push(val);
        }

        std::vector<int> res(st.size());
        for(int i = st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};

class Solution1 {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::vector<int> res;
        for(int a : asteroids) {
            bool destroyed = false;
            while(res.size() && res.back() > 0 && a < 0 && !destroyed) {
                if(res.back() >= -a) destroyed = true;
                if(res.back() <= -a) res.pop_back();
            }
            if(!destroyed) res.push_back(a);
        }
        return res;
    }
};