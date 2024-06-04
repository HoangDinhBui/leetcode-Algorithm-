#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for (char c : s) {
            if (!st.empty() && (c == 'B' && st.top() == 'A' || c == 'D' && st.top() == 'C')) {
                st.pop();
            } else {
                st.push(c);
            }
        }
        return st.size();
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.minLength(s) << endl;

    return 0;
}