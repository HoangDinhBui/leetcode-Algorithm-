#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int squareOfDigits(int n) {
        int s = 0;
        while(n > 0) {
            int digit = n % 10;
            s += digit*digit;
            n /= 10;
        }
        return s;
    }
    bool isHappy(int n) {
       unordered_set<int> set;
       while(n != 1 && !set.count(n)) {
            set.insert(n);
            n = squareOfDigits(n);
       }
       return n == 1;
    }
};

int main() {
    int n;
    cin >> n;
    Solution s;
    cout << s.isHappy(n);

    return 0;
}