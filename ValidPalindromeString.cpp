#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string s1;
        int i;
        if(s == " ")
            return true;
         for(char c : s) {
            if(isalnum(c)){
                s1 += tolower(c);
            }
        }
        
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        return s1 == s2;
    }
};

int main() {
    Solution solution;
    
    // Test cases
    string test1 = "A man, a plan, a canal: Panama";
    string test2 = "race a car";
    
    cout << "Test Case 1: " << (solution.isPalindrome(test1) ? "true" : "false") << endl;
    cout << "Test Case 2: " << (solution.isPalindrome(test2) ? "true" : "false") << endl;
    
    return 0;
}
