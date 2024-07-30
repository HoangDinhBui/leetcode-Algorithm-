#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string unit[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hunrs[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string thous[] = {"", "M", "MM", "MMM"};

        return thous[num/1000] + hunrs[(num%1000)/100] + tens[((num%1000)%100)/10] + unit[((num%1000)%100)%10];
    }
};

int main() {
    int num = 1232;

    Solution s;
    cout << s.intToRoman(num) << endl;

    return 0;
}