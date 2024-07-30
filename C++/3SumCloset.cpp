#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum1 = 0;
        int sum = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size() - 2; i++) {
            int l = i + 1; 
            int r = nums.size() - 1;
            while(l < r) {
                sum1 = nums[l] + nums[r] + nums[i];
                if(abs(sum1 - target) < abs(sum - target)) {
                    sum = sum1;
                } 
                if (sum1 > target){ 
                    r--;
                } else if(sum1 < target) {
                    l++;
                } else {
                    return target;
                }
            }
        }
        return sum;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int result = solution.threeSumClosest(nums, target);
    
    cout << "Closest sum to target " << target << " is: " << result << endl;

    return 0;
}
