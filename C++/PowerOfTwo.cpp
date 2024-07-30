#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        return log2(n) == (int)log2(n);
    }
};

int main() {
    Solution sol;
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if (sol.isPowerOfTwo(num))
        cout << num << " is a power of two." << endl;
    else
        cout << num << " is not a power of two." << endl;

    return 0;
}
