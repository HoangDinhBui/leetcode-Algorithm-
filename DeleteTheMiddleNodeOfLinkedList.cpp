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
    ListNode* deleteMiddle(ListNode* head) {
        int length = 0;
        ListNode *curr = head;
        while(curr) {
            length++;
            curr = curr->next;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy;
        ListNode *prev = dummy;
        while(fast && fast->next) {
            prev = slow;
            slow = slow -> next;
            fast = fast->next->next;
        }
        if(length % 2 == 0) {
            ListNode *middle = slow->next;
            slow->next = middle->next;
        } else prev->next = slow->next;

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
    // Create a test list: 1 -> 2 -> 3 -> 4 -> 5
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(values);

    cout << "Original list: ";
    printLinkedList(head);

    Solution solution;
    head = solution.deleteMiddle(head);

    cout << "List after deleting middle: ";
    printLinkedList(head);

    // Create a test list with an even number of nodes: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    values = {1, 2, 3, 4, 5, 6};
    head = createLinkedList(values);

    cout << "Original list with even number of nodes: ";
    printLinkedList(head);

    head = solution.deleteMiddle(head);

    cout << "List after deleting middle in even list: ";
    printLinkedList(head);

    return 0;
}
