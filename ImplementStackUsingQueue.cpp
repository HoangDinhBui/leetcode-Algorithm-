#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    MyStack() {}

    queue<int> q1, q2;

    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q1.pop();
        q1.swap(q2);
        return x;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack *obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
}