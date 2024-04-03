#include <iostream>

using namespace std;

// Định nghĩa cấu trúc cho node trong danh sách liên kết
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Không cần khởi tạo biến third ở đây
        ListNode* dummy = new ListNode(); // Node giả định, không chứa giá trị thực sự
        ListNode* last = dummy;
        
        while (list1 && list2) {
            if (list1->val < list2->val) {
                last->next = list1;
                list1 = list1->next;
            } else {
                last->next = list2;
                list2 = list2->next;
            }
            last = last->next;
        }
        
        // Nối phần còn lại của danh sách chưa được hợp nhất
        last->next = list1 ? list1 : list2;
        
        // Trả về danh sách mới (bỏ qua node giả định)
        return dummy->next;
    }
};

// Hàm để in danh sách liên kết
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Tạo danh sách liên kết thứ nhất: 1 -> 3 -> 5
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    // Tạo danh sách liên kết thứ hai: 2 -> 4 -> 6
    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    // Tạo một đối tượng của lớp Solution
    Solution solution;
    
    // Hợp nhất hai danh sách và lưu kết quả vào một biến mới
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);
    
    // In danh sách đã hợp nhất
    cout << "Merged List: ";
    printList(mergedList);

    // Giải phóng bộ nhớ
    delete list1;
    delete list2;
    delete mergedList;

    return 0;
}
