#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> stk;
        vector<int> res(prices.size());
        
        for (int i = prices.size() - 1; i >= 0; --i) {
            while (!stk.empty() && stk.top() > prices[i]) {
                stk.pop();
            }
            res[i] = stk.empty() ? prices[i] : prices[i] - stk.top();
            stk.push(prices[i]);
        }
        
        return res;
    }
};

int main() {
    Solution solution;
    
    vector<int> test1 = {8, 4, 6, 2, 3};
    vector<int> result1 = solution.finalPrices(test1);
    cout << "Result: ";
    for (int price : result1) {
        cout << price << " ";
    }
    cout << endl;
    
    vector<int> test2 = {1, 2, 3, 4, 5};
    vector<int> result2 = solution.finalPrices(test2);
    cout << "Result: ";
    for (int price : result2) {
        cout << price << " ";
    }
    cout << endl;

    return 0;
}
