#include <string>
#include <vector>
#include <stack>

using std::vector;
using std::string;
using std::stack;

class Solution {
    public:
        int calPoints(vector<string>& operations) {
            int sum = 0;
            stack<int> s;

            for (string i : operations) {
                if (i == "C") {
                    sum -= s.top();
                    s.pop();

                } else if (i == "+") {
                    int tmp = s.top();
                    s.pop();
                    int add = tmp + s.top();
                    s.push(tmp);
                    s.push(add);
                    sum += add;

                } else if (i == "D") {
                    int tmp = 2 * s.top();
                    s.push(tmp);
                    sum += tmp;
                    
                } else {
                    s.push(std::stoi(i));
                    sum += s.top();
                }
            }
            return sum;
        }
};
