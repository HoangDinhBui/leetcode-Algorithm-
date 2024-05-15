#include <iostream>
#include <vector>

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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *curr = head;
        ListNode *prev = dummy;
        
        while (curr) {
            if (curr->next && curr->next->val < curr->val) {
                while (prev->next && prev->next->val < curr->next->val) {
                    prev = prev->next;
                }
                ListNode* tmp = prev->next;
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = tmp;
                prev = dummy;
            } else {
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val;
        if (current->next) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

// Main function to test the solution
int main() {
    // Create a test list: 4 -> 2 -> 1 -> 3
    vector<int> values = {4, 2, 1, 3};
    ListNode* head = createLinkedList(values);

    cout << "Original list: ";
    printLinkedList(head);

    Solution solution;
    head = solution.insertionSortList(head);

    cout << "Sorted list: ";
    printLinkedList(head);

    return 0;
}
