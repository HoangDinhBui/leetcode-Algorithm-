#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            int tmp = target - nums[i];
            if(mp.count(tmp)){
                return {mp[tmp], i};
            }
            mp[nums[i]] = i;
        }
        return {0, 0};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);
    if (result.size() == 2) {
        cout << "Indices of the two numbers whose sum is equal to " << target << " are: ";
        for (int i : result) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
