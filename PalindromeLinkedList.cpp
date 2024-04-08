#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ~ListNode() {
        ListNode* temp;
        while (next != nullptr) {
            temp = next;
            next = next->next;
            delete temp;
        }
    }
};
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> stack;
        ListNode *curr = head;
        while(curr != NULL){
            stack.push(curr->val);
            curr = curr->next;
        }
        curr = head;
        while(curr != NULL){
            if(curr->val != stack.top()){
                return false;
            }
            stack.pop();
            curr = curr->next;
        }
        if(stack.empty())
            return true;
        return false;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);
    Solution solution;
    cout << "The linked list is " << (solution.isPalindrome(head) ? "a palindrome." : "not a palindrome.") << endl;  
    return 0;
}