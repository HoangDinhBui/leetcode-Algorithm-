#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1)
            return x;
        long left = 1; // Use long to avoid overflow
        long right = x;
        while (left < right) {
            long mid = left + (right - left) / 2;
            long square = mid * mid;

            if (square == x)
                return mid;
            else if (square < x)
                left = mid + 1;
            else
                right = mid;
        }
        // Since we are looking for integer square root, return left - 1 when square exceeds x
        return left - 1;
    }
};

int main() {
    Solution sol;
    int num;

    cout << "Enter a number: ";
    cin >> num;

    cout << "Square root of " << num << " is: " << sol.mySqrt(num) << endl;

    return 0;
}
