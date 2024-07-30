#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int total = 0;
        int i = 0;
        unordered_map<char, int> num ={
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        while(i < s.length()){
            if(num[s[i]] < num[s[i+1]]){
                total -= num[s[i]];
            }else{
                total += num[s[i]];
            }
            i++;
        }
        return total;
    }
};

int main() {
    Solution solution;
    string roman = "IV"; // Đổi số La Mã "IV" thành số nguyên
    int result = solution.romanToInt(roman);
    cout << "Equivalent integer for Roman numeral " << roman << " is: " << result << endl;
    return 0;
}
