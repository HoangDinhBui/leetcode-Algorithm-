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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) // Corrected condition
            return head;
        
        ListNode *oddNode = head;
        ListNode *evenNode = head->next;
        ListNode *evenHead = evenNode; // Save the head of the even list

        while (evenNode && evenNode->next) {
            oddNode->next = evenNode->next;
            oddNode = oddNode->next;
            evenNode->next = oddNode->next;
            evenNode = evenNode->next;
        }

        oddNode->next = evenHead; // Link the end of the odd list to the head of the even list
        return head;
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

    // Reorganize the list by odd and even positions
    Solution solution;
    ListNode* newHead = solution.oddEvenList(head);

    std::cout << "List after rearranging odd and even nodes: ";
    printLinkedList(newHead);

    // Clean up memory
    deleteLinkedList(newHead);

    return 0;
}
