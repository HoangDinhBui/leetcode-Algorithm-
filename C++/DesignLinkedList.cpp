#include <iostream>
#include <vector>
using namespace std;

class MyLinkedList {
public:
    vector<int> ans;
    MyLinkedList() {
        
    }
    
    int get(int index) {
        for(int i = 0; i < ans.size(); i++) {
            if(i == index)
                return ans[i];
        }
        return -1;    
    }
    
    void addAtHead(int val) {
        ans.insert(ans.begin(), val);
    }
    
    void addAtTail(int val) {
        ans.insert(ans.end(), val);
    }
    
    void addAtIndex(int index, int val) {
        if(index < ans.size())
            ans.insert(ans.begin()+index, val);
        else if(index == ans.size())
            ans.push_back(val);
    }
    
    void deleteAtIndex(int index) {
        if(index < ans.size())
            ans.erase(ans.begin()+index);
    }
};

int main() {
    MyLinkedList *obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1, 2);
    cout << "Element at index 1: " << obj->get(1) << endl; 
}
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */