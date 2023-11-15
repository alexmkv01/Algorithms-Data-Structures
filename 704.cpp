#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int mid;

        while (left <= right){
            mid = (left+right)/2;

            if (nums[mid] < target){
                // discard left half
                left = mid+1;
            } 
            else if (nums[mid] > target){
                // discard right half
                right = mid-1;
            } else {
                // found
                return mid;
            }
        }
        return -1;
    }
};