#include <iostream>
#include <vector>
#include <set>

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
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        backtrack(ans, temp, nums, used);
        set<vector<int>> s(ans.begin(), ans.end());
        vector<vector<int>> fans(s.begin(), s.end());

        return fans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2};

    vector<vector<int>> result = solution.permuteUnique(nums);

    cout << "Unique permutations:" << endl;
    for (const auto& perm : result) {
        cout << "[";
        for (int num : perm) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
