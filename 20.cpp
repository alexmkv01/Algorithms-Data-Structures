#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> bracketStack;

        for (char c : s){
            if (c=='(' || c=='{' || c=='['){
                bracketStack.push(c);
            } else if (c==')' || c=='}' || c==']'){
                if (bracketStack.empty() ) return false;
                
                char top = bracketStack.top();
                bracketStack.pop();

                if (c == ')' && top != '(')  return false; 
                if (c == ']' && top != '[')  return false; 
                if (c == '}' && top != '{')  return false; 
            }
        }
        return bracketStack.empty();
    }
};