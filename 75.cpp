#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counts[] = {0,0,0};
        for (int n : nums){
            counts[n] += 1;
        }

        int i=0;
        for (int j=0; j<3; j++){
            for (int n=0; n<counts[j]; n++){
                nums[i] = j;
                i++;
            }
        }
    }

};