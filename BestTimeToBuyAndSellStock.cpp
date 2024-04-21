#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int maxPro = 0;
       int minPro = prices[0];
       for(int i = 0; i < prices.size(); i++){
           minPro = min(prices[i], minPro);
           maxPro = max(maxPro, prices[i] - minPro);
        }
        return maxPro;
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution sol;
    int maxProfit = sol.maxProfit(prices);
    
    cout << "Maximum profit: " << maxProfit << endl;
    
    return 0;
}
