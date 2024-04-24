#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy;
        ListNode *q = &dummy;
        // Move q ahead by n steps
        for(int i = 0; i < n; i++){
            q = q->next;
        }
        // Move both p and q until q reaches the end
        while(q->next){
            p = p->next;
            q = q->next;
        }
        // Remove the nth node from the end
        ListNode *temp = p->next;
        p->next = p->next->next;
        delete temp;
        
        return dummy.next;
    }
};

void printList(ListNode *head) {
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

    Solution sol;
    int n = 2;
    cout << "Original list: ";
    printList(head);
    ListNode *newHead = sol.removeNthFromEnd(head, n);
    cout << "After removing " << n << "th node from end: ";
    printList(newHead);

    // Free memory
    while (newHead) {
        ListNode *temp = newHead;
        newHead = newHead->next;
        delete temp;
    }

    return 0;
}
