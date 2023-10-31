#include <iostream>
#include <vector>

using std::vector;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int leftPtr = 1;
        for (int rightPtr = 1; rightPtr < nums.size(); rightPtr++){

            if (nums[rightPtr] != nums[rightPtr - 1]){
                // update
                nums[leftPtr] = nums[rightPtr];
                leftPtr +=1;
            }
        }
        return leftPtr;
    }

};