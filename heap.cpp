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

        while (heap[i] < heap[i/2]){
            swap(heap[i], heap[i/2]);
            i/=2;
        }


    }
};