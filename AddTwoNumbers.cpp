#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = new ListNode();
        ListNode* tmp = answer;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry){
            int num1 = (l1 != nullptr ? l1->val : 0);
            int num2 = (l2 != nullptr ? l2->val : 0);
            l1 = (l1 != nullptr ? l1 -> next : nullptr);
            l2 = (l2 != nullptr ? l2 -> next : nullptr);
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            ListNode *newNode = new ListNode(sum % 10);
            tmp-> next = newNode;
            tmp = tmp -> next;
        }
        return answer -> next;
    }
};

// Utility function to print a linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    // Creating first list: 2 -> 4 -> 3
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    
    // Creating second list: 5 -> 6 -> 4
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    cout << "List 1: ";
    printList(l1);

    cout << "List 2: ";
    printList(l2);

    cout << "Sum: ";
    printList(result);

    // Clean up memory
    delete l1;
    delete l2;
    delete result;

    return 0;
}
