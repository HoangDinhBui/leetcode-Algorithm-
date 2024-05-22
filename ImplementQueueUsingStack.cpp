#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> stack1;
    stack<int> stack2;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack1.push(x);
    }
    
    int pop() {
        while(stack1.size() > 1) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int x = stack1.top();
        stack1.pop();
        while(!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return x;
    }
    
    int peek() {
        while(stack1.size() > 1) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int x = stack1.top();
        while(!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return x;
    }
    
    bool empty() {
        return stack1.empty();
    }
};

int main() {
    MyQueue *q = new MyQueue();
    q->push(1);
    q->push(2);
    q->push(3);
    cout << q->empty();

    return 0;
}