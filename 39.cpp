
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        combinationSumHelper(candidates, target, 0, 0);
        return results;
    }

private:
    vector<vector<int>> results;
    vector<int> subset;

    void combinationSumHelper(vector<int>& candidates, int target, int i, int current) {
        // base case 1: invalid combination 
        if (i >= candidates.size() || current > target){
            return;
        }

        // base case 2: found
        if (current == target){
            results.push_back(subset);
            return;
        }

        // case 1: include candidate (left branch)
        subset.push_back(candidates[i]);
        combinationSumHelper(candidates, target, i, current + candidates[i]); // no increment

        // case 2: exclude (right branch)
        subset.pop_back();
        combinationSumHelper(candidates, target, i+1, current); // increment

    }
};