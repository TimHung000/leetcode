#include <vector>
#include <string>

class Solution {
private:
    bool isPalindrome(std::string& s, int l, int r) {
        while(l < r) {
            if(s[l++] != s[r--])
                return false;
        }
        return true;
    }
    
    void dfs(int startIdx, std::string& s, std::vector<std::string>& part, std::vector<std::vector<std::string>>& res) {
        if(startIdx == s.size()) {
            res.push_back(part);
            return;
        }

        for(int i = startIdx; i < s.size(); ++i) {
            if(isPalindrome(s, startIdx, i)) {
                part.push_back(s.substr(startIdx, i - startIdx + 1));
                dfs(i + 1, s, part, res);
                part.pop_back();
            }
        }
    }
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> res;
        std::vector<std::string> part;
        dfs(0, s, part, res);
        return res;
    }
};