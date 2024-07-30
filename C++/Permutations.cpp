#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& temp, vector<int>& nums, vector<bool>& used) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                temp.push_back(nums[i]);
                used[i] = true;
                backtrack(ans, temp, nums, used);
                temp.pop_back();
                used[i] = false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        backtrack(ans, temp, nums, used);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = solution.permute(nums);
    
    cout << "Permutations:" << endl;
    for (const auto& permutation : permutations) {
        cout << "[";
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}
