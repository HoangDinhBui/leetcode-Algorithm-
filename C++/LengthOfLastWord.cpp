#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int i = s.length()-1;
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }
        return count;
    }
};

int main() {
    string a;
    cout << "Enter string: ";
    cin >> a;
    Solution s;
    cout << "Length of last word is: " << s.lengthOfLastWord(a) << endl;
    return 0; 
}