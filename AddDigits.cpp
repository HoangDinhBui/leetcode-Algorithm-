#include <iostream>

using namespace std;

class Solution {
public:
    int AddDigits(int num) {
        if(num == 0) return 0;
        else return 1 + (num - 1) % 9;
    } 
};

int main() {
    int num;
    cin >> num;
    Solution s;
    cout << s.AddDigits(num);
    
    return 0;
}