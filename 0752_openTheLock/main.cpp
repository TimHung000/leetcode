#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

class Solution {
public:
    int openLock(std::vector<std::string>& deadends, std::string target) {
        std::unordered_set<std::string> uset(deadends.begin(), deadends.end());
        std::queue<std::string> myQueue;
        if(uset.find("0000") != uset.end()) return -1;
        myQueue.push("0000");
        uset.insert("0000");
        int step = 0;
        while(!myQueue.empty()) {
            for(int i = myQueue.size(); i > 0; --i) {
                std::string cur = myQueue.front();
                myQueue.pop();
                if(cur == target) return step;
                for(int str_idx = 0; str_idx < 4; ++str_idx) {
                    std::string down = cur;
                    down[str_idx] = (down[str_idx] - '0' - 1 + 10) % 10 + '0';
                    if(uset.find(down) == uset.end()){
                        myQueue.push(down);
                        uset.insert(down);
                    }
                    std::string up = cur;
                    up[str_idx] = (up[str_idx] - '0' + 1 + 10) % 10 + '0';
                    if(uset.find(up) == uset.end()) {
                        myQueue.push(up);
                        uset.insert(up);
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};

int main() {
    std::vector<std::string> test = {"0201","0101","0102","1212","2002"};
    std::string target = "0202";
    
    Solution sol;
    sol.openLock(test, target);

    return 0;
}