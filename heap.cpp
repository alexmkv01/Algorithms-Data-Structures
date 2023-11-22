#include <vector>

using namespace std;

class Heap {
// leftChild of i = heap[2 * i]
// rightChild of i = heap[(2 * i) + 1] 
// parent of i = heap[i // 2]

public:
    vector<int> heap;

    Heap() {
        heap.push_back(0);
    }

    void push(int val){
        heap.push_back(val);
        int i = heap.size()-1;

        while (heap[i] < heap[i/2]) {
            swap(heap[i], heap[i/2]);
            i/=2;
        }
    }

    int pop() {
        if (heap.size() == 1) {
            // Normally we would throw an exception if heap is empty.
            return -1;
        }
        if (heap.size() == 2) {
            int res = heap[heap.size() - 1];
            heap.pop_back();
            return res;
        }

        int res = heap[1];
        // Move last value to root
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();
        int i = 1;
        // Percolate down
        while (2*i < heap.size()) {
            if (2*i+1 < heap.size() && heap[2*i+1] < heap[2*i] && heap[i] > heap[2*i+1]) {
                // Swap right child
                swap(heap[i], heap[2*i+1]);
                i = 2*i+1;
            } else if (heap[i] > heap[2*i]) {
                // Swap left child
                swap(heap[i], heap[2*i]);
                i = 2*i;
            } else {
                break;
            }
        }
        return res;
    }

    int top() {
        if (heap.size() > 1) {
            return heap[1];
        }
        // Normally we would throw an exception if heap is empty.
        return -1;
    }
};