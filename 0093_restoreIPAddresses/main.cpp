#include <vector>
#include <string>
#include <algorithm>

class Solution {
private:
    void backtrack(int startIdx, int dots, std::string curIP, std::string& s, std::vector<std::string>& res) {
        if(dots == 4 && startIdx == s.size()) {
            res.push_back(curIP.substr(0, curIP.size()-1));
            return;
        }
        if(dots > 4)
            return;

        for(int i = startIdx; i < std::min(startIdx+3, (int)s.size()); ++i) {
            if(std::stoi(s.substr(startIdx, i - startIdx + 1)) <= 255 && (s[startIdx] != '0' || startIdx == i))
                backtrack(i+1, dots+1, curIP + s.substr(startIdx, i - startIdx + 1) + '.', s, res);
        }
    }
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> res;
        if(s.size() <= 12)
            backtrack(0, 0, "", s, res);
        return res;
    }
};

int main() {
    std::string test = "0000";
    Solution sol;
    sol.restoreIpAddresses(test);
    return 0;
}