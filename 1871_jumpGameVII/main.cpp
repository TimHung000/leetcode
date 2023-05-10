#include <string>
#include <queue>
#include <algorithm>
class Solution {
public:
    // exceed time limit
    bool canReach(std::string s, int minJump, int maxJump) {
        std::queue<int> myQueue;
        myQueue.push(0);

        while(!myQueue.empty()) {
            int curPos = myQueue.front();
            myQueue.pop();
            for(int i = minJump; i <= maxJump; ++i) {
                if(curPos + i < s.size() && s[curPos+i] == '0') {
                    if(curPos + i == s.size() - 1)
                        return true;
                    myQueue.push(curPos+i);
                }
            }
        }
        return false;
    }

    bool canReach1(std::string s, int minJump, int maxJump) {
        int farthestReach = 0;
        std::queue<int> myQueue;
        myQueue.push(0);
        while(!myQueue.empty()) {
            int curPos = myQueue.front();
            myQueue.pop();
            int start = std::max(curPos + minJump, farthestReach + 1);
            int end = std::min(curPos + maxJump + 1, (int)s.size());
            for(int i = start; i < end; ++i) {
                if(s[i] == '0') {
                    if(i == s.size()-1)
                        return true;
                    myQueue.push(i);
                }
            }
            farthestReach = curPos + maxJump;
        }
        return false;
    }
};

int main() {
    std::string test = std::string("00111010");
    Solution sol;
    sol.canReach(test, 3, 5);
    return 0;
}