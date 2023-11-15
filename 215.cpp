#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int index = nums.size() - k;
        return quickSelect(nums, 0, nums.size() - 1, index);
    }
private:
    int quickSelect(vector<int> &arr, int s, int e, int k){
        int pivot = arr[e];
        int insertPtr = s;

        for (int i=s; i<e; i++){
            if (arr[i] <= pivot){
                // swap
                swap(arr[i], arr[insertPtr]);
                insertPtr++;
            }
        }
        swap(arr[insertPtr], arr[e]);
        if (k < insertPtr){
            return quickSelect(arr, s, insertPtr-1, k);
        } 
        if (k > insertPtr){
            return quickSelect(arr, insertPtr + 1, e, k);
        }
        return arr[insertPtr];   
    }
};
