#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> q1; // with elements
    queue<int> q2; // empty (for stacking)

public:
    MyStack() {}
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int top = q1.front();
        q1.pop();
        swap(q1,q2);
        return top;
    }
    
    int top() {
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int top = q1.front();
        q2.push(top); // not removed
        q1.pop();
        swap(q1,q2);
        return top;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */