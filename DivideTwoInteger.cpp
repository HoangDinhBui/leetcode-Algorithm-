#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return dividend >= 0 ? INT_MAX : INT_MIN;
        }
        
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        if(dividend == INT_MIN && divisor == 1)
            return INT_MIN;
            
        int quotient = 0;
        long long a = labs(dividend), b = labs(divisor);
        
        while (a >= b) {
            long long temp = b;
            int count = 1;
            while ((temp << 1) <= a) {
                temp <<= 1;
                count <<= 1;
            }
            a -= temp;
            quotient += count;
        }
        
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
            return -quotient;
        } else {
            return quotient;
        }
    }
};

int main(){
    int dividend, divisor;
    cout << "Enter dividend: ";
    cin >> dividend;
    cout << "Enter divisor: ";
    cin >> divisor;
    Solution s;
    cout << "Result is: " << s.divide(dividend, divisor);
}