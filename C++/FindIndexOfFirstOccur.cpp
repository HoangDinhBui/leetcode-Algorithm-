#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        int lengthhay = haystack.size();
        int lengthneedle = needle.size();
        while(i < lengthhay){
            if(haystack.substr(i, lengthneedle) == needle){
                return i;
            }
            i++;
        }
        return -1;
    }
};

int main() {
    Solution solution;

    string haystack = "hello";
    string needle = "ll";

    int result = solution.strStr(haystack, needle);
    cout << "Index of the first occurrence: " << result << endl;

    return 0;
}
