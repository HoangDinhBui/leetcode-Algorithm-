#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int curr = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[curr] = nums[i];
                curr++;
            }
        }

        return curr;
    }
};

int main() {
    std::vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    Solution solution;
    int newSize = solution.removeElement(nums, val);

    std::cout << "New size of the array after removing " << val << " is: " << newSize << std::endl;
    std::cout << "Remaining elements in the array: ";
    for (int i = 0; i < newSize; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
