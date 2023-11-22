#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> minHeap(stones.begin(), stones.end());
        
        while (minHeap.size() > 1){
            int h1 = minHeap.top();
            minHeap.pop();
            int h2 = minHeap.top();
            minHeap.pop();

            int diff = abs(h1-h2);
            if (diff != 0){
                minHeap.push(diff);
            }
        } 
        return !minHeap.empty() ? minHeap.top() : 0;
    }
};