#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(result, candidates, target, current, 0);
        return result;
    }
    
private:
    void backtrack(vector<vector<int>>& result, vector<int>& candidates, int target, vector<int>& current, int start) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            if (target - candidates[i] >= 0) {
                current.push_back(candidates[i]);
                backtrack(result, candidates, target - candidates[i], current, i);
                current.pop_back();
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> combinations = solution.combinationSum(candidates, target);
    
    cout << "Combinations that sum up to " << target << ":\n";
    for (const auto& combination : combinations) {
        cout << "[";
        for (int i = 0; i < combination.size(); ++i) {
            cout << combination[i];
            if (i < combination.size() - 1)
                cout << ", ";
        }
        cout << "]\n";
    }
    
    return 0;
}
