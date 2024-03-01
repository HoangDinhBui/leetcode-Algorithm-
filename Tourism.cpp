#include <iostream>
#include <climits> // Để sử dụng INT_MAX
using namespace std;

int n, c[100][100], x[100];
int visited[100]; // Mảng lưu những thành phố đã đi qua
int ans = INT_MAX; // Chi phí nhỏ nhất
const int BEST_RESULT = 234; // Kết quả tốt nhất đã biết

// Hàm kiểm tra xem có thể thăm thành phố j từ thành phố i hay không
bool isValid(int i, int j) {
    if (!visited[j] && c[i][j] != 0) // Chưa thăm và có đường đi giữa i và j
        return true;
    return false;
}

// Hàm thử tất cả các cấu hình có thể của hành trình du lịch
void Try(int i, int d) 
{
    for (int j = 1; j <= n; j++) 
    {
        if (isValid(x[i - 1], j)) 
        {
            x[i] = j;
            visited[j] = 1; // Đánh dấu thành phố j đã được thăm
            if (i == n) 
            { // Nếu đã thăm hết tất cả các thành phố
                ans = min(ans, d + c[x[n]][x[1]]); // Cập nhật chi phí nhỏ nhất
            } else {
                // Đánh giá cận
                if (d + c[x[i - 1]][j] < ans && d + c[x[i - 1]][j] + c[j][x[1]] < BEST_RESULT) // Kiểm tra nếu chi phí hiện tại đã vượt quá chi phí nhỏ nhất
                    Try(i + 1, d + c[x[i - 1]][j]); // Thử tiếp tục từ thành phố tiếp theo
            }
            visited[j] = 0; // Trả lại trạng thái của thành phố j
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    
    // Bắt đầu từ thành phố 1
    x[1] = 1;
    visited[1] = 1;
    
    Try(2, 0); // Bắt đầu thử từ thành phố thứ 2, chi phí hiện tại là 0
    
    cout << ans << endl; // In ra chi phí nhỏ nhất
    return 0;
}
