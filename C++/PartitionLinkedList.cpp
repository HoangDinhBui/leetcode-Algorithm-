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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;

        ListNode* dummyLesser = new ListNode(-1);
        ListNode* dummyGreater = new ListNode(-1);
        ListNode* currLesser = dummyLesser;
        ListNode* currGreater = dummyGreater;
        
        ListNode* curr = head;
        while (curr) {
            if (curr->val < x) {
                currLesser->next = curr;
                currLesser = currLesser->next;
            } else {
                currGreater->next = curr;
                currGreater = currGreater->next;
            }
            curr = curr->next;
        }
        
        // Terminate the greater list
        currGreater->next = nullptr;

        // Connect lesser list to greater list
        currLesser->next = dummyGreater->next;

        // Get the new head
        ListNode* newHead = dummyLesser->next;
        
        // Clean up dummy nodes
        delete dummyLesser;
        delete dummyGreater;
        
        return newHead;
    }
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val;
        if (current->next) cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

// Helper function to delete a linked list and free memory
void deleteLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
}

int main() {
    // Create a sample linked list
    vector<int> values = {1, 4, 3, 2, 5, 2};
    ListNode* head = createLinkedList(values);

    cout << "Original list: ";
    printLinkedList(head);

    // Partition the list
    Solution solution;
    int x = 3;
    ListNode* newHead = solution.partition(head, x);

    cout << "Partitioned list around " << x << ": ";
    printLinkedList(newHead);

    // Clean up memory
    deleteLinkedList(newHead);

    return 0;
}
