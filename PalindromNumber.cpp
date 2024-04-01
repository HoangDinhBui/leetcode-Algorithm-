#include <iostream>
using namespace std;

class Solution {
    public:
        long long reverse(int n){
            long long res = 0;
            while(n > 0){
                res = res * 10 + n % 10;
                n /= 10;
            }
            return res;
        }
        bool isPalindrome(int x) {
            return (x < 0 ? false : (long long)x == reverse(x));
        }
};

int main() {
    Solution sol;
    int number;
    
    cout << "Enter a number: ";
    cin >> number;
    
    if(sol.isPalindrome(number)) {
        cout << number << " is a palindrome." << endl;
    } else {
        cout << number << " is not a palindrome." << endl;
    }
    
    return 0;
}