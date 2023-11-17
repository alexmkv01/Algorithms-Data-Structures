#include <stdio.h>

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr){
            return NULL;
        }
        if (key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else if (key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else {
            // target node has been found

            // case 1: 0 or 1 child nodes.
            // returning either the single child node OR a nullptr
            if (root->left == nullptr){
                return root->right; 
            }
            else if (root->right == nullptr){
                return root->left;
            } 
            // case 2: 2 child nodes
            else{
                TreeNode* minNode = minValNode(root->right);
                root->val = minNode->val;
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }

private:
    TreeNode* minValNode(TreeNode* root) {
        TreeNode *curr = root;
        while (curr != nullptr && curr->left != nullptr){
            curr = curr->left;
        }
        return curr;
    }
};