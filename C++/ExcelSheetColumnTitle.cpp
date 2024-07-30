#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while(columnNumber > 0) {
            columnNumber--;
            int remain = columnNumber % 26;
            res += (char)(remain + 'A');
            columnNumber /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    int columnNumber;
    cin >> columnNumber;
    Solution s;
    cout << s.convertToTitle(columnNumber);
    return 0;
}