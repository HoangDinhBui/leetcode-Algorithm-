#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        
        for (int i = 0; i < s.length(); ++i) {
            if (!stk.empty() && s[i] == stk.top()) {
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
    
    string test1 = "abbaca";
    cout << "Input: " << test1 << " -> Output: " << solution.removeDuplicates(test1) << endl;
    
    string test2 = "azxxzy";
    cout << "Input: " << test2 << " -> Output: " << solution.removeDuplicates(test2) << endl;

    return 0;
}
