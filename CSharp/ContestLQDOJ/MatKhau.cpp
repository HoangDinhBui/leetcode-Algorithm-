#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Hàm kiểm tra chuỗi đối xứng
bool isPalindrome(const string &s) {
    int l = 0;
    int r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

// Hàm đếm số cách chọn đoạn thỏa mãn
int countPalinCombine(int k, int m, const string &s, const vector<int> &start_pos, const vector<int> &end_pos) {
    int n = s.size();
    int count = 0;
    
    if (k == 1) {
        for (int start = 0; start <= n - m; ++start) {
            string segment = s.substr(start, m);  // Trích xuất đoạn con có độ dài m từ vị trí start
            if (isPalindrome(segment)) {
                count++;
            }
        }
        return count;  // Trả về số cách chọn thỏa mãn
    }
    
    // Trích xuất đoạn đã chọn trước
    int start_index = start_pos[0] - 1;  // Chuyển sang chỉ số 0-based
    int length = end_pos[0] - start_pos[0] + 1;  // Tính độ dài đoạn con
    string selected_segment = s.substr(start_index, length);  // Trích xuất đoạn con từ chuỗi s

    for (int start = 0; start <= n - m; ++start) {
        string segment_k = s.substr(start, m); 
        if (isPalindrome(selected_segment + segment_k) || isPalindrome(segment_k + selected_segment)) {
            count += 1;
        }
    }

    return count; 
}

int main() {
    int k, m;
    cin >> k >> m;  
    string s;
    cin >> s; 

    vector<int> start_pos(k - 1);  // Khởi tạo vector chứa vị trí bắt đầu của các đoạn
    vector<int> end_pos(k - 1);  // Khởi tạo vector chứa vị trí kết thúc của các đoạn
    for (int i = 0; i < k - 1; ++i) {
        int L, R;
        cin >> L >> R;  // Nhập giá trị L và R
        start_pos[i] = L;  // Lưu vị trí bắt đầu
        end_pos[i] = R;  // Lưu vị trí kết thúc
    }

    int result = countPalinCombine(k, m, s, start_pos, end_pos);  
    cout << result << endl; 
    return 0;  
}
