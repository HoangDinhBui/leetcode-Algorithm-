#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (int i = 0; i < s.length(); i++) {
            char cur = s[i];
            char peek = ' ';
            if (!stack.empty()) {
                peek = stack.top();
            }
            if (cur == '{' || cur == '(' || cur == '[') {
                stack.push(cur);
            } else if ((cur == '}' && peek == '{') || 
                       (cur == ')' && peek == '(') || 
                       (cur == ']' && peek == '[')) {
                stack.pop();
            } else {
                return false;
            }
        }
        return stack.empty();
    }
};

int main() {
    Solution solution;
    string input;
    cout << "Enter a string with parentheses, brackets, and curly braces: ";
    cin >> input;
    if (solution.isValid(input)) {
        cout << "The input string has valid parentheses, brackets, and curly braces." << endl;
    } else {
        cout << "The input string does not have valid parentheses, brackets, and curly braces." << endl;
    }
    return 0;
}
