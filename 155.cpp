#include <vector>

using namespace std;

class MinStack {
    public:

        // Attribute
        vector <pair<int, int>> stack;

        // constructor
        MinStack() {}
        
        // ---------------------------- METHODS ----------------------------
        void push(int val) {
            int minNum;
            if (stack.empty()) {
                minNum = val;
            } else {
                minNum = min(getMin(), val);
            }
            stack.push_back({val, minNum});
        }
        
        void pop() {
            stack.pop_back();
        }
        
        int top() {
            return stack.back().first;
        }
        int getMin(){
            return stack.back().second;
        }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */