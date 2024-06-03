#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> stu;
        stack<int> sw;
        for(int i = 0; i < students.size(); i++)
            stu.push(students[i]);
        for(int i = students.size() - 1; i >= 0; i--)
            sw.push(sandwiches[i]);
        int size = stu.size();
        int atm = 0;
        while(!stu.empty()) {
            if(stu.front() == sw.top()) {
                stu.pop();
                sw.pop();
                atm = 0;
            } else {
                stu.push(stu.front());
                stu.pop();
                atm++;
            }
            if(atm == size) break;
        }
        return stu.size();
    }
};

int main() {
    vector<int> students {1, 1, 0, 0};
    vector<int> sandwiches {0, 1, 0, 1};
    Solution s;
    cout << "Result is: " << s.countStudents(students, sandwiches) << endl;

    return 0;
}