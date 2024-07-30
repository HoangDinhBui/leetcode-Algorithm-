#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.empty()) return -1; // Trả về giá trị mặc định nếu vector rỗng
        
        // Tạo một map để lưu trữ số lần xuất hiện của từng phần tử
        map<int, int> hash;
        
        // Tính toán số lần xuất hiện của mỗi phần tử trong vector và lưu vào map
        for(int i = 0; i < nums.size(); i++){
            hash[nums[i]]++;
        }
        
        // Duyệt qua map để tìm phần tử có count là 1 và trả về nó
        for(auto it = hash.begin(); it != hash.end(); ++it){
            if(it->second == 1) // Trả về key đầu tiên có count là 1
                return it->first;
        }
        
        return -1; // Trả về -1 nếu không tìm thấy phần tử duy nhất
    }
};

int main() {
    Solution solution;
    
    vector<int> nums = {1, 2, 3, 4, 5, 2, 3, 6, 7, 8, 8, 9};
    int result = solution.singleNumber(nums);
    
    if(result != -1)
        cout << "Single number: " << result << endl;
    else
        cout << "No single number found." << endl;
    
    return 0;
}
