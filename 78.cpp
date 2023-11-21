#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // Clear previous contents (if any)
        results.clear();
        subset.clear();

        // Start the DFS
        dfs(nums, 0);
        return results;
    }

private:
    vector<vector<int>> results;
    vector<int> subset;

    void dfs(vector<int>& nums, int i){
        // base case
        if (i >= nums.size()){
            results.push_back(subset);
            return;
        }

        // include
        subset.push_back(nums[i]);
        dfs(nums,i+1);

        // dont include
        subset.pop_back();
        dfs(nums,i+1);
    }
};