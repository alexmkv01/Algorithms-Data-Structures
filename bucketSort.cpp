#include <vector>

using namespace std;

vector<int> bucketSort(vector<int>& arr) {
    // Assuming arr only contains 0, 1 or 2
    vector<int> counts = {0, 0, 0};

    // Count the quantity of each val in arr
    for (int n: arr) {
        counts[n]+=1;
    }

    int i = 0;
    for (int n = 0; counts.size(); n++) {
        for (int j = 0; j < counts[n]; j++) {
            arr[i] = n;
            i++;
        }
    }
    return arr;
}
