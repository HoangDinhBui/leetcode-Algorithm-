#include <iostream>
using namespace std;// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *tmp = head;
        int size = 0;
        while(tmp != NULL) {
            size++;
            tmp = tmp->next;
        }
        size = size / 2;
        int j = 0;
        ListNode *tmp1 = head;
        while(j < size) {
            tmp1 = tmp1->next;
            j++;
        }

        return tmp1;
    }
};

// Helper function to print the linked list
void printList(ListNode *head) {
    ListNode *curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list: 1->2->3->4->5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;

    cout << "Original list: ";
    printList(head);

    // Find the middle node
    ListNode *middle = solution.middleNode(head);

    cout << "Middle node value: " << middle->val << endl;

    // Free memory
    ListNode *temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
