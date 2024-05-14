#include <iostream>
#include <vector>

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0)
            return head;

        ListNode *curr = head;
        int length = 1;
        while(curr->next) {
            length++;
            curr = curr->next;
        }

        // Make the list circular
        curr->next = head;

        // Optimize k by reducing it modulo the length of the list
        k %= length;
        int step = length - k;

        // Find the new tail: (length - k) steps from the head
        ListNode *newTail = head;
        for(int i = 1; i < step; i++) {
            newTail = newTail->next;
        }

        // Break the cycle and set the new head
        ListNode *newHead = newTail->next;
        newTail->next = nullptr;

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
        std::cout << current->val;
        if (current->next) std::cout << " -> ";
        current = current->next;
    }
    std::cout << std::endl;
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
    std::vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(values);

    std::cout << "Original list: ";
    printLinkedList(head);

    // Rotate the list
    Solution solution;
    int k = 7;  // Example with k larger than the length of the list
    ListNode* newHead = solution.rotateRight(head, k);

    std::cout << "List after rotating " << k << " times to the right: ";
    printLinkedList(newHead);

    // Clean up memory
    deleteLinkedList(newHead);

    return 0;
}
