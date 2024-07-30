#include <math.h>
#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long reNum = 0;
        while(x != 0){
           int digits = x % 10;
           reNum = reNum * 10 + digits;
           x = x / 10;
        }
        if(reNum > INT_MAX || reNum < INT_MIN)
            return 0;
        return reNum;
    }
};

int main(){
    int x;
    cout << "Enter x: ";
    cin >> x;
    Solution s;
    cout << "Reverse number: " << s.reverse(x) << endl;
    return 0;
}