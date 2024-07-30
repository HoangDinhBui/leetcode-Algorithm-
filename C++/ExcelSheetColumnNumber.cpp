#include <iostream>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for(char c : columnTitle) 
            res = res * 26 + (c - 'A' + 1);
        return res;
    }
};

int main() {
    string columnTitle;
    cin >> columnTitle;
    Solution s;
    cout << s.titleToNumber(columnTitle);
    return 0;
}