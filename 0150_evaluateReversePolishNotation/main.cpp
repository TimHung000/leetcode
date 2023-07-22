#include <vector>
#include <string> //stoi
#include <unordered_map>
#include <functional>
#include <stack>


class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::unordered_map<std::string, std::function<int(int, int)>> map = {
            { "+" , [] (int a, int b) { return a + b; } },
            { "-" , [] (int a, int b) { return a - b; } },
            { "*" , [] (int a, int b) { return a * b; } },
            { "/" , [] (int a, int b) { return a / b; } }
        };
        std::stack<int> stack;
        for (std::string& s : tokens) {
            if (map.find(s) == map.end()) {
                stack.push(std::stoi(s));
            } else {
                int op1 = stack.top();
                stack.pop();
                int op2 = stack.top();
                stack.pop();
                stack.push(map[s](op2, op1));
            }
        }
        return stack.top();
    }
};

class Solution1 {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> s;
        for(int i = 0; i < tokens.size(); ++i){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int op2=s.top();
                s.pop();
                int op1=s.top();
                s.pop();
                switch(tokens[i][0]){
                    case '+':
                        s.push(op1+op2);
                        break;
                    case '-':
                        s.push(op1-op2);
                        break;
                    case '*':
                        s.push(op1*op2);
                        break;
                    case '/':
                        s.push(op1/op2);
                        break;
                    default:
                        throw "operator is" + tokens[i] + "is not allowed";
                }
            }
            else{
                s.push(std::stoi(tokens[i]));
            }
        }
        return s.top();
    }
};