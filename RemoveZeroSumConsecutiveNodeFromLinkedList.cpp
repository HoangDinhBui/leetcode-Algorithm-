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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *curr = dummy;
        while(curr) {
            ListNode *next = curr->next;
            int sum = 0;
            while(next) {
                sum += next->val;
                if(sum == 0) {
                    curr->next = next->next;
                }
                next = next->next;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
};

// Helper function to create a linked list from a vector of values
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

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val;
        if (current->next) std::cout << " -> ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage:
    std::vector<int> values = {1, 2, -3, 3, 1};  // Define the vector of values here
    ListNode* head = createLinkedList(values);
    
    Solution solution;
    ListNode* result = solution.removeZeroSumSublists(head);
    
    std::cout << "Resulting Linked List: ";
    printLinkedList(result);
    
    // Free the allocated memory
    while (result) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
