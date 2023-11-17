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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> values;
        return inorder(root, values);
    }
private:
    vector<int> inorder(TreeNode* root, vector<int> &values) {
        // base case
        if (root == nullptr){
            return values;
        }
        inorder(root->left, values);
        values.push_back(root->val);
        inorder(root->right, values);
        return values; 
    }
};
