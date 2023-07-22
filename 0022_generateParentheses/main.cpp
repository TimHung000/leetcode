#include <string>
#include <vector>

class Solution {
private:
    void helper(std::vector<std::string>& res, std::string& s, int open, int close, int n) {
        if(open == n && close == n) {
            res.push_back(s);
        }

        if(open < n) {
            s.push_back('(');
            helper(res, s, open + 1, close, n);
            s.pop_back();
        }

        if(close < open) {
            s.push_back(')');
            helper(res, s, open, close + 1, n);
            s.pop_back();
        }
    }
public:
    // backtracking
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        std::string s;
        helper(res, s, 0, 0, n);
        return res;
    }

    // dp
    std::vector<std::string> generateParenthesis1(int n) {
        // dp[i] contains all the valid parenthesis pobbible of length 2*i
        /*
            dp[2] = {(()), ()()}
            dp[3] =
            ( + dp[0] + ) + dp[2] = ()(()) and ()()()
            ( + dp[1] + ) + dp[1] = (())()
            ( + dp[2] + ) + dp[0] = ((())) and (()())
        **/
        std::vector<std::vector<std::string>> dp(n+1);
        dp[0] = {""};
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < i; ++j) {
                // std::vector<std::string> left = dp[j];
                // std::vector<std::string> right = dp[i-j-1];
                // for(int k = 0; k < left.size(); ++k) {
                //     for(int l = 0; l < right.size(); ++l) {
                //         dp[i].push_back('(' + left[k] + ')' + right[l]);
                //     }
                // }
                for(int k = 0; k < dp[j].size(); ++k) {
                    for(int l = 0; l < dp[i-j-1].size(); ++l) {
                        std::string s = '(' + dp[j][k] + ')' + dp[i-j-1][l];
                        dp[i].push_back(s);
                    }
                }
            }
        }
        return dp[n];
    }
};

int main(int argc, char** argv) {
    Solution sol;
    std::vector<std::string> res = sol.generateParenthesis(1);
    return 0;
}
