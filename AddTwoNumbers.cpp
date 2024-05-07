#include <iostream>

using namespace std;

// Định nghĩa cấu trúc cho một nút trong danh sách liên kết
struct ListNode {
    int val;            // Giá trị của nút
    ListNode *next;     // Con trỏ trỏ đến nút tiếp theo trong danh sách
    ListNode() : val(0), next(nullptr) {}                         // Constructor mặc định
    ListNode(int x) : val(x), next(nullptr) {}                   // Constructor với một tham số
    ListNode(int x, ListNode *next) : val(x), next(next) {}      // Constructor với hai tham số
};

// Lớp chứa các phương thức để thực hiện phép cộng hai danh sách liên kết
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = new ListNode();     // Khởi tạo một danh sách liên kết mới để lưu kết quả
        ListNode* tmp = answer;                 // Con trỏ tạm để di chuyển trong danh sách liên kết kết quả
        int carry = 0;                          // Biến để lưu giá trị nhớ khi thực hiện phép cộng
        while(l1 != nullptr || l2 != nullptr || carry){ // Duyệt qua cả hai danh sách và giá trị nhớ
            int num1 = (l1 != nullptr ? l1->val : 0);     // Lấy giá trị của nút từ danh sách 1
            int num2 = (l2 != nullptr ? l2->val : 0);     // Lấy giá trị của nút từ danh sách 2
            l1 = (l1 != nullptr ? l1 -> next : nullptr);  // Di chuyển con trỏ danh sách 1 đến nút tiếp theo
            l2 = (l2 != nullptr ? l2 -> next : nullptr);  // Di chuyển con trỏ danh sách 2 đến nút tiếp theo
            int sum = num1 + num2 + carry;                // Tính tổng của hai giá trị và giá trị nhớ
            carry = sum / 10;                             // Cập nhật giá trị nhớ
            ListNode *newNode = new ListNode(sum % 10);    // Tạo một nút mới với giá trị là phần dư của tổng
            tmp-> next = newNode;                         // Liên kết nút mới với danh sách kết quả
            tmp = tmp -> next;                            // Di chuyển con trỏ tạm đến nút mới
        }
        return answer -> next;                              // Trả về danh sách kết quả (bỏ qua nút đầu tiên)
    }
};

// Hàm utility để in ra danh sách liên kết
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

// Hàm main - chương trình chính
int main() {
    // Tạo hai danh sách liên kết
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Tạo một đối tượng Solution để gọi phương thức addTwoNumbers
    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // In ra các danh sách và kết quả
    cout << "List 1: ";
    printList(l1);

    cout << "List 2: ";
    printList(l2);

    cout << "Sum: ";
    printList(result);

    // Giải phóng bộ nhớ
    delete l1;
    delete l2;
    delete result;

    return 0;
}
