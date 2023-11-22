#include <vector>
#include <iostream>

using namespace std;

void merge(vector<int>& arr, int s, int m, int e){

    // get our two arrays
    vector<int> left = {arr.begin() + s, arr.begin() + m+1}; // m+1 because non-inclusive
    vector<int> right = {arr.begin() + m+1, arr.begin() + e+1};

    int l = 0; // left Pointer
    int r = 0; // right Pointer
    int i = s; // index for array

    while (l<left.size() && r < right.size()){
        // compare
        if (left[l] <= right[r]) { // <= for stable sorting
            arr[i] = left[l];
            l++;
        } else {
            arr[i] = right[r];
            r++;
        }
        i++;
    }
    // one of halfs may still have elements remaining
    while (l < left.size()){
        arr[i] = left[l];
        l++;
        i++;
    }
    while (r < right.size()){
        arr[i] = right[r];
        r++;
        i++;
    }
}

vector<int> mergeSort(vector<int>& arr, int s, int e) {

    // base case: length <= 1 (arr with 1 element is sorted by default)
    if (e-s+1 <= 1){
        return arr;
    }

    // inductive case
    int m = (s+e)/2;  
    
    mergeSort(arr,s,m); // left half
    mergeSort(arr,m+1,e); // right half

    merge(arr,s,m,e); // merge left and right halves

    return arr;
}


int main(){
    vector<int> arr = {5,1,1,2,0,0};
    vector<int> sortedArr = mergeSort(arr, 0, arr.size()-1);

    for (int i=0; i<sortedArr.size(); i++){
        std::cout << sortedArr[i] << " ";
    }
    std::cout << "\n";
    return 0;
}