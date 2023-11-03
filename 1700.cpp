#include <iostream>
#include <vector>
#include<queue>
#include<stack>

using namespace std;
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int> q;
        stack<int> s;

        bool done = false;
        for (int i=n-1; i>=0 ; i--){
            s.push(sandwiches[i]);
        } 
        for(int i=0;i<n;i++){
            q.push(students[i]);
        }

        int leaves = 0;
        while (!done){
            if (q.empty()){
                return 0;
            }
            else if (leaves == q.size()){
                done=true;
            }
            else if (q.front() == s.top()){
                s.pop();
                q.pop();
                leaves = 0;
            } else{
                q.push(q.front());
                q.pop();
                leaves+=1;
            }
        }
        return q.size();
    }
};