#include <vector>
#include <iostream>

using namespace std;

vector<int> quickSort(vector<int> &arr, int s, int e){
    // length == 0 
    if ((e-s+1) <=1) { 
        return arr;
    }

    int insertPtr = s;
    int pivot = arr[e];

    for (int i=s; i<e; i++){
        if (arr[i] < pivot){
            // swap
            int tmp = arr[insertPtr];
            arr[insertPtr] = arr[i];
            arr[i] = tmp;
            insertPtr++;
        }
    }

    arr[e] = arr[insertPtr];
    arr[insertPtr] = pivot;

    quickSort(arr, s, insertPtr-1); // because arr[insertPtr] already in correct place
    quickSort(arr,insertPtr+1,e);

    return arr;
}

int main(){
    vector<int> arr = {5,1,1,2,0,0};
    vector<int> sortedArr = quickSort(arr, 0, arr.size()-1);

    for (int i=0; i<sortedArr.size(); i++){
        std::cout << sortedArr[i] << " ";
    }
    std::cout << "\n";
    return 0;
}