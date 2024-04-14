#include <climits>
#include <cfloat>
#include <iostream> 

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        else if(n == INT_MIN){
            if(x <= 1)
                return 1;
            else if(x > 1)
                return 1/myPow(x, -(n+1));
            return 0;
        }
        else if(n == 1)
            return x;
        else if(n < 0)
            return 1/myPow(x, -n);
        else if(n % 2 == 0)
            return myPow(x*x, n/2);
        else
            return x*myPow(x, n-1);
    }
};

int main(){
    int x, n;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter n: ";
    cin >> n;
    Solution s;
    cout << "Result is: " << s.myPow(x, n);
    return 0;
}