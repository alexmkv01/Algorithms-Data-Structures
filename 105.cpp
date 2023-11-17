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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // base case
        if (preorder.size() == 0 || inorder.size() == 0){
            return NULL;
        }

        // root of subtree
        TreeNode* root = new TreeNode(preorder[0]);
        preorder.erase(preorder.begin()); 

        // Calculate index of our root in the inorder list
        auto it = find(inorder.begin(), inorder.end(), root->val);
        int index = distance(inorder.begin(), it); 

        // partition (to determine which branch its child elements should go to)
        vector<int> left(inorder.begin(), inorder.begin() + index);
        vector<int> right(inorder.begin() + index + 1, inorder.end());

        root->left = buildTree(preorder, left);
        root->right = buildTree(preorder, right);
        
        return root;
    }
};