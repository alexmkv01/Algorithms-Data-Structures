#include <stdio.h>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x)   : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<int> path = {};
        return hasPathSumHelper(root, targetSum, path);
    }

private:
    bool hasPathSumHelper(TreeNode* root, int targetSum, vector<int>& currentPath) {
        if (!root){
            return false;
        }
        currentPath.push_back(root->val);
        int currentSum = pathSum(currentPath);

        if (!root->left && !root->right && targetSum == currentSum){
            return true;
        }
        if (hasPathSumHelper(root->left, targetSum, currentPath)){
            return true;
        }
        if (hasPathSumHelper(root->right, targetSum, currentPath)){
            return true;
        }
        currentPath.pop_back();
        return false;
    }

    int pathSum(vector<int>& path){
        int total = 0;
        for (int i : path){
            total += i;
        }
        return total;
    }
};