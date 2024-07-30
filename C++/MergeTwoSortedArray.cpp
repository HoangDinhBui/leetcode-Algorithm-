#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while(i >= 0 && j >= 0){
            if(nums1[i] < nums2[j]){
                nums1[k--] = nums2[j--];
            }else{
                nums1[k--] = nums1[i--];
            }
        }
        while(j >= 0){
            nums1[k--] = nums2[j--];
        }
    }
};

int main() {
    vector<int> nums1 = {1, 3, 5, 8, 10, 20};
    vector<int> nums2 = {2, 4, 6};
    int m = 6;
    int n = 3;

    Solution solution;

    solution.merge(nums1, m, nums2, n);
    cout << "Merged array: ";
    
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}