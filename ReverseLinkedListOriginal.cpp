#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *aft = nullptr;
        while(curr != nullptr) {
            aft = curr->next;
            curr->next = prev;
            prev = curr;
            curr = aft;
        }
        return prev;
    }
};

void printList (ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    ListNode* reversedHead = sol.reverseList(head);

    cout << "Reversed list: ";
    printList(reversedHead);
    ListNode* temp;
    while (reversedHead != nullptr) {
        temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }

    return 0;
}