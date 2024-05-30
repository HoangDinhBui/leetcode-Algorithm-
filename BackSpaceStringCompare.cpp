#include <iostream>
#include <stack>
#include <string>

using namespace std;

string processString(const string& str) {
    stack<char> stk;
    for (char ch : str) {
        if (ch != '#') {
            stk.push(ch);
        } else if (!stk.empty()) {
            stk.pop();
        }
    }
    
    string result;
    while (!stk.empty()) {
        result = stk.top() + result;
        stk.pop();
    }
    
    return result;
}

bool backspaceCompare(const string& s, const string& t) {
    return processString(s) == processString(t);
}

int main() {
    // Test cases
    string s1 = "ab#c", t1 = "ad#c";
    string s2 = "ab##", t2 = "c#d#";
    string s3 = "a#c", t3 = "b";

    cout << boolalpha;
    cout << backspaceCompare(s1, t1) << endl; 
    cout << backspaceCompare(s2, t2) << endl; 
    cout << backspaceCompare(s3, t3) << endl; 

    return 0;
}
