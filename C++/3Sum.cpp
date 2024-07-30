#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int target = 0;
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        for(int i = 0; i < nums.size(); i++) {
            int l = i + 1, r = nums.size() - 1;
            while(l < r) {
                int sum = nums[l] + nums[i] + nums[r];
                if(sum == 0) {
                    s.insert({nums[i], nums[r], nums[l]});
                    l++;
                    r--;
                } else if (sum < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        for(auto triplets : s)
            ans.push_back(triplets);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = solution.threeSum(nums);
    
    cout << "Unique triplets with sum 0:" << endl;
    for (const auto& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
