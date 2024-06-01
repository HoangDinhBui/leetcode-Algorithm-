#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> stack;
        for (int i = 0; i < logs.size(); i++) {
            if (logs[i] == "../") {
                if (!stack.empty()) {
                    stack.pop();
                }
            } 
            else if (logs[i] != "./") {
                stack.push(logs[i]);
            }
        }
     
        return stack.size();
    }
};

int main() {
    Solution solution;
    vector<string> logs1 = {"d1/", "d2/", "../", "d21/", "./"};
    vector<string> logs2 = {"d1/", "d2/", "./", "d3/", "../", "d31/"};
    vector<string> logs3 = {"d1/", "../", "../", "../"};

    cout << "Number of operations for logs1: " << solution.minOperations(logs1) << endl;
    cout << "Number of operations for logs2: " << solution.minOperations(logs2) << endl;
    cout << "Number of operations for logs3: " << solution.minOperations(logs3) << endl;

    return 0;
}
