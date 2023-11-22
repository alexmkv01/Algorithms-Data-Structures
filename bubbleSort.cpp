#include <vector>
#include <iostream>

using namespace std;

vector<int> bubbleSort(const vector<int>& nums) {
    vector<int> sortedArr = nums;
    int n = sortedArr.size();
    bool swapped;

    for (int i = 0; i < n-1; i++) {
        swapped = false;

        for (int j = 0; j < n-i-1; j++) {
            if (sortedArr[j] > sortedArr[j + 1]) {
                // Swap sortedArr[j] and sortedArr[j+1]
                swap(sortedArr[j], sortedArr[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped in inner loop, the array is already sorted
        if (!swapped) {
            break;
        }
    }
    return sortedArr;
}

int main() {
    vector<int> arr = {5, 1, 1, 2, 0, 0};
    vector<int> sortedArr = bubbleSort(arr);

    for (int i = 0; i < sortedArr.size(); i++) {
        cout << sortedArr[i] << " ";
    }
    return 0;
}
