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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *tmp = head;
        while(tmp && tmp->next){
            if(tmp->val == tmp->next->val){
                ListNode *dupl = tmp->next;
                tmp->next = tmp->next->next;
                delete dupl;
            }else{
                tmp = tmp->next;
            }
        }
        return head;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Creating the linked list: 1 -> 1 -> 2
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);

    Solution solution;
    ListNode* cleanedList = solution.deleteDuplicates(head);

    // Printing the cleaned linked list
    cout << "Cleaned Linked List: ";
    printList(cleanedList);

    return 0;
}
