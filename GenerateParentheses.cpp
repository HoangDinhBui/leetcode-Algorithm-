#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void count(vector<string> &ans, string temp, int n, int l, int r) {
        // Base case: when the count of left and right parentheses equals 'n'
        if (l == n && r == n) {
            ans.push_back(temp); // Add the current combination to the result vector
            return;
        }
        // Recursive cases:
        if (l < n) {
            temp.push_back('('); // Add '(' if the count of left parentheses is less than 'n'
            count(ans, temp, n, l + 1, r); // Recur with one more left parenthesis added
            temp.pop_back(); // Backtrack: remove the last added '('
        }
        if (l > r) {
            temp.push_back(')'); // Add ')' if the count of left parentheses is greater than 'r' (right parentheses)
            count(ans, temp, n, l, r + 1); // Recur with one more right parenthesis added
            temp.pop_back(); // Backtrack: remove the last added ')'
        }
    }
    
    vector<string> generateParenthesis(int n) {
        int l = 0, r = 0; // Initialize counts of left and right parentheses
        vector<string> ans; // Initialize the result vector
        string temp; // Initialize a temporary string to store current combination
        count(ans, temp, n, l, r); // Generate all valid combinations recursively
        return ans; // Return the result vector
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    vector<string> result = sol.generateParenthesis(n);
    cout << "All possible combinations of parentheses for n = " << n << " are:" << endl;
    for (const string& s : result) {
        cout << s << endl;
    }
    return 0;
}
