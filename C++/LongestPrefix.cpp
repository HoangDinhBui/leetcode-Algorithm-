#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre = strs[0]; // Lấy chuỗi đầu tiên từ vector làm chuỗi tiền tố ban đầu
        for(int i = 1; i < strs.size(); i++) { // Duyệt qua các chuỗi từ vị trí thứ hai trong vector
            while(strs[i].find(pre, 0) != 0) { // Kiểm tra nếu chuỗi pre không phải là tiền tố của chuỗi thứ i
                pre = pre.substr(0, pre.length()-1); // Loại bỏ ký tự cuối cùng của chuỗi pre
                if(pre.empty()) return ""; // Nếu chuỗi pre trở thành rỗng, không còn tiền tố nào, trả về chuỗi rỗng
            }
        }
        return pre; // Trả về chuỗi tiền tố dài nhất chung cho tất cả các chuỗi trong vector
    }
};

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    Solution sol;
    string longest_prefix = sol.longestCommonPrefix(strs);
    cout << "Longest common prefix: " << longest_prefix << endl; // Xuất chuỗi tiền tố dài nhất chung
    return 0;
}
