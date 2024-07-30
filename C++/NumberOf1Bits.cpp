#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n > 0){
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
};

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    Solution s;
    cout << "Number of 1 bits is: " << s.hammingWeight(n) << endl;
    
    return 0;
}