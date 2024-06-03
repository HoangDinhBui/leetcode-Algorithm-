#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = 0; 
        for (int i = 0; i < tickets.size(); ++i) {
            if (i <= k) {
                res += min(tickets[i], tickets[k]);
            } else {
                res += min(tickets[i], tickets[k] - 1);
            }
        }
        return res;
    }
};

int main() {
    vector<int> tickets {2, 3, 2};
    int k = 2;
    Solution s;
    cout << "Result is: " << s.timeRequiredToBuy(tickets, k) << endl;

    return 0;
}