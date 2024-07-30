#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void solve(string digits, int i, vector<string>& ans, string output){
        if(i >= digits.length()){
            ans.push_back(output);
            return;
        }

        string temp = mp[digits[i]];
        for(int j=0; j<temp.length(); j++){
            solve(digits, i+1, ans, output + temp[j]);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output = "";
        int i = 0;
        if(digits.length() == 0){
            return ans;
        }
        solve(digits, i, ans, output);
        return ans;
    }
};

int main() {
    Solution solution;
    string input = "23";
    vector<string> result = solution.letterCombinations(input);
    
    cout << "All letter combinations for " << input << " are:\n";
    for(auto combination : result) {
        cout << combination << " ";
    }
    cout << endl;
    
    return 0;
}
