#include <vector>

using namespace std;

class Heap {
// leftChild of i = heap[2 * i]
// rightChild of i = heap[(2 * i) + 1] 
// parent of i = heap[i // 2]

public:
    vector<int> heap_;

    Heap() {
        heap_.push_back(0);
    }
};