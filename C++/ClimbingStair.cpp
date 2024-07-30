#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int a[46];
        a[1] = 1, a[2] = 2;
        for(int i = 3; i <= 45; i++)
            a[i] = a[i-1] + a[i-2];
        return a[n];
    }
};

int main() {
    int n;
    cin >> n;
    Solution s;
    int res = s.climbStairs(n);
    cout << "Result is: " << n << endl;

    return 0;
}