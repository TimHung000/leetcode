#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    std::string findDifferentBinaryString(std::vector<std::string>& nums) {
        std::string res = "";
        for(int i = 0; i < nums.size(); ++i)
            res += nums[i][i] == '0' ? '1' : '0';
        return res;
    }
};

class Solution1 {
private:
    std::string backtrack(int i, std::string curStr, std::unordered_set<std::string>& numSet) {
        if(i == numSet.size()) {
            if(numSet.find(curStr) == numSet.end())
                return curStr;
            return "";
        }
        std::string res;
        curStr += '0';
        res = backtrack(i+1, curStr, numSet);
        if(res != "")
            return res;
        curStr[i] = '1';
        res = backtrack(i+1, curStr, numSet);
        if(res != "")
            return res;
        return "";
    }
public:
    std::string findDifferentBinaryString(std::vector<std::string>& nums) {
        std::unordered_set<std::string> numSet(nums.begin(), nums.end());
        std::string curStr = "";
        return backtrack(0, curStr, numSet);
    }
};

class Solution2 {
private:
    std::string res = "";
    void backtrack(int i, std::string curStr, std::unordered_set<std::string>& numSet) {
        if(res != "")
            return;
        if(i == numSet.size()) {
            if(numSet.find(curStr) == numSet.end())
                res = curStr;
            return;
        }
        backtrack(i + 1, curStr + '0', numSet);
        backtrack(i + 1, curStr + '1', numSet);
    }
public:
    std::string findDifferentBinaryString(std::vector<std::string>& nums) {
        res = "";
        std::unordered_set<std::string> numSet(nums.begin(), nums.end());
        backtrack(0, "", numSet);
        return res;
    }
};