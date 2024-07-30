#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1) {
            return 1;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

int main() {
    int n;
    cin >> n;
    Solution s;
    cout << s.climbStairs(n) << endl;
    
    return 0;
}