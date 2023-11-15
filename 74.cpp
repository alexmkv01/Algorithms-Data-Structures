#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // flatten 
        vector<int> newMatrix = flattenMatrix(matrix);
        return search(newMatrix, target) != -1;
    }

private:
    vector<int> flattenMatrix(const vector<vector<int>>& matrix) {
        vector<int> flattened;
        for (const vector<int>& row : matrix) {
            for (int element : row) {
                flattened.push_back(element);
            }
        }
        return flattened;
    }
    int search(vector<int>& arr, int target){
        int left=0, right=arr.size()-1;
        int mid;

        while (left <= right){
            mid = (left + right) / 2;
            if (arr[mid] < target){
                // discard left side
                left = mid+1;
            } else if (arr[mid] > target){
                // discard right side
                right = mid-1;
            } else {
                // found
                return mid;
            }
        }
        return -1;
    }
    
};
