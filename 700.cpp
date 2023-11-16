#include <stdio.h>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // base case
        if (root == nullptr){
            return NULL;
        }

        if (val > root->val){
            // search right
            return searchBST(root->right, val); 
        } 
        else if (val < root->val){
            // search left
            return searchBST(root->left, val);
        }
        else {
            return root;
        }
    }
};