#include <vector>

using std::vector;

// Implementing a stack is trivial using a dynamic array
// (which we implemented earlier).

class Stack{
    // Implementation of a stack with a trivial dynamic array
    public:
        vector <int> stack;

        Stack(){}; // empty constructor

        void push(int n){
            stack.push_back(n);
        }

        int pop(){
            int val = stack[stack.size()-1];
            stack.pop_back();
            return val;
        }
};