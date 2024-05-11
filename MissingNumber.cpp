#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int Nsum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int sum = n*(n+1)/2;
        return sum - Nsum;
    }
};

int main() {
    vector<int> nums = {3, 0, 1};
    Solution sol;
    int missing = sol.missingNumber(nums);
    cout << "The missing number is: " << missing << endl;
    return 0;
}
