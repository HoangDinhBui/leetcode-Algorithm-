#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int right = 0;
        int left = nums.size() - 1;
        while(right <= left){
            int mid = (right + left)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                right = mid + 1;
            else
                left = mid - 1;
        }
        return left + 1;
    }
};

int main(){
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    Solution solution;

    int result = solution.searchInsert(nums, target);
    cout << "Index of " << target << " or where to insert: " << result << endl;

    return 0;
}