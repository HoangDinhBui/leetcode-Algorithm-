#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;
        
        for (int i = 0; i < s.length(); ++i) {
            if (!stk.empty() && (stk.top() == s[i] + 32 || stk.top() == s[i] - 32)) {
                stk.pop();
            } else {
                stk.push(s[i]);
            }
        }
        
        string res;
        while (!stk.empty()) {
            res = stk.top() + res;
            stk.pop();
        }
        
        return res;
    }
};

int main() {
    Solution solution;
    
    string test1 = "leEeetcode";
    cout << "Result: " << solution.makeGood(test1) << endl;
    
    string test2 = "abBAcC";
    cout << "Result: " << solution.makeGood(test2) << endl;

    string test3 = "s";
    cout << "Result: " << solution.makeGood(test3) << endl;

    return 0;
}
