#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> stk;
        string res;
        for (char c : s) {
            if (c == '(') {
                if (!stk.empty()) {
                    res += c;
                }
                stk.push(c);
            } else if (c == ')') {
                stk.pop();
                if (!stk.empty()) {
                    res += c;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    string test1 = "(()())(())";
    string test2 = "(()())(())(()(()))";
    string test3 = "()()";

    cout << "Test 1: " << solution.removeOuterParentheses(test1) << endl;  
    cout << "Test 2: " << solution.removeOuterParentheses(test2) << endl;  
    cout << "Test 3: " << solution.removeOuterParentheses(test3) << endl;  

    return 0;
}
