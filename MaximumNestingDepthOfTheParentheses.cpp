#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        stack<char> stack;
        int maxDepth = 0;
        int currentDepth = 0;
        for (char c : s) {
            if (c == '(') {
                stack.push(c);
                currentDepth++;
                if (currentDepth > maxDepth) {
                    maxDepth = currentDepth;
                }
            } else if (c == ')' && !stack.empty()) {
                stack.pop();
                currentDepth--;
            }
        }
        return maxDepth;
    }
};

int main() {
    Solution solution;
    
    string s1 = "(1+(2*3)+((8)/4))+1";
    cout << "Max depth of \"" << s1 << "\": " << solution.maxDepth(s1) << endl;

    string s2 = "(1)+((2))+(((3)))";
    cout << "Max depth of \"" << s2 << "\": " << solution.maxDepth(s2) << endl;

    string s3 = "1+(2*3)/(2-1)";
    cout << "Max depth of \"" << s3 << "\": " << solution.maxDepth(s3) << endl;

    string s4 = "1";
    cout << "Max depth of \"" << s4 << "\": " << solution.maxDepth(s4) << endl;

    return 0;
}
