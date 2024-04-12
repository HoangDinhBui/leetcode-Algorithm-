#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(n == 1 && (digits[0] == 0 || digits[0] == 9)){
            digits[0] = (digits[0] + 1) % 10; 
            if(digits[0] == 0) { 
                digits.insert(digits.begin(), 1);
            }
            return digits;
        }
        for(int i = n - 1; i >= 0; i--){
            if(digits[i] < 9){
                digits[i]++;
                return digits;
            }else{
                digits[i] = 0;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    Solution sol;
    vector<int> digits = {1};
    vector<int> result = sol.plusOne(digits);

    for (int digit : result) {
        cout << digit << " ";
    }
    cout << endl;

    return 0;
}