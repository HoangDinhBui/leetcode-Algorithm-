#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cstdlib>  

using namespace std;

class Solution {
public:
    int sum(stack<int> stack) {
        int total = 0;
        while (!stack.empty()) {
            total += stack.top();
            stack.pop();
        }
        return total;
    }

    int calPoints(vector<string>& operations) {
        stack<int> stack;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "D") {
                int top = stack.top();
                stack.push(2 * top);
            } else if (operations[i] == "C") {
                stack.pop();
            } else if (operations[i] == "+") {
                int top1 = stack.top();
                stack.pop();
                int top2 = stack.top();
                stack.push(top1);  
                stack.push(top1 + top2);
            } else {
                stack.push(atoi(operations[i].c_str()));
            }
        }
        return sum(stack);
    }
};

int main() {
    Solution solution;
    vector<string> operations = {"5", "2", "C", "D", "+"};
    cout << "Tổng điểm: " << solution.calPoints(operations) << endl;
    return 0;
}
