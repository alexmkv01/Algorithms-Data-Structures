#include <vector>

using std::vector;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int concats = 2;
        vector<int> ans;

        for (int j=0; j<concats; j++){
            for (int i=0; i<nums.size(); i++){
                ans.push_back(nums[i]);
            }
        }
        
        return ans;
    }
};