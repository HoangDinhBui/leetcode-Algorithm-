#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next || !head->next->next) 
            return false;
        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) 
                return true;
        }
        return false;
    }
};

int main() {
    // Tạo danh sách liên kết mẫu có vòng lặp
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next; // tạo vòng lặp

    Solution solution;
    bool hasCycleResult = solution.hasCycle(head);
    
    if (hasCycleResult) {
        cout << "The linked list has a cycle." << endl;
    } else {
        cout << "The linked list does not have a cycle." << endl;
    }

    // Giải phóng bộ nhớ
    ListNode *current = head;
    while (current != nullptr) {
        ListNode *temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
