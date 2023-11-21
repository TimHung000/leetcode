#include <vector>
#include <string>

class Solution {
private:
    bool isUniq(std::string& s) {
        std::vector<int> count(26, 0);
        for(char c: s) {
            if(count[c-'a']++ > 0)
                return false;
        }
        return true;
    }
    void backtrack(int i, std::string curStr, std::vector<std::string>& arr, int& res) {
        if(i == arr.size()) {
            if(isUniq(curStr) && curStr.size() > res)
                res = curStr.size();
            return;
        }
        backtrack(i+1, curStr, arr, res);
        backtrack(i+1, curStr + arr[i], arr, res);
    }
public:
    int maxLength(std::vector<std::string>& arr) {
        int res = 0;
        backtrack(0, "", arr, res);
        return res;
    }
};