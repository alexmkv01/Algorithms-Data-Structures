#include <vector>
#include <iostream>

using namespace std;

vector<int> sortArray(vector<int>& nums) {

        for (int i=1; i<nums.size(); i++){
            int j = i-1; // so we do not get out of bounds error

            while (j>=0 && nums[j] > nums[j+1]) {
                // swap
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
                j--;
            }
        }
        return nums;
}

int main(){
    vector<int> arr = {5,1,1,2,0,0};
    vector<int> sortedArr = sortArray(arr);

    for (int i=0; i<sortedArr.size(); i++){
        std::cout << sortedArr[i] << " ";
    }
    return 0;
}